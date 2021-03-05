package main

import (
	"chatroom/common/message"
	"encoding/binary"
	"encoding/json"
	"fmt"
	"net"
)

func login(userId int, userPwd string) (err error) {
	//定协议
	//fmt.Printf("userId=%d, userPwd=%s\n", userId, userPwd)
	//return nil

	conn, err := net.Dial("tcp", "localhost:8888")
	if err != nil {
		fmt.Println("net.Dial error: ", err)
		return
	}
	defer conn.Close()

	//准备通过conn将消息发送出去，先组织消息
	var mes message.Message
	mes.Type = message.LoginMesType
	//创建一个loginMes结构体
	var loginMes message.LoginMes
	loginMes.UserId = userId
	loginMes.UserPwd = userPwd

	data, err := json.Marshal(loginMes)
	if err != nil {
		fmt.Println("json.Marshal error: ", err)
		return
	}

	mes.Data = string(data)

	data, err = json.Marshal(mes)
	if err != nil {
		fmt.Println("json.Marshal error: ", err)
		return
	}
	//此时这个data已经序列化组织好了，这才是要发送的东西
	//1、先发送data的长度告知服务端
	var pkgLen uint32
	pkgLen = uint32(len(data))

	//获取到data的长度以后要转换为一个byte类型的切片，   Write(b []byte) (n int, err error)
	var buf [4]byte
	binary.BigEndian.PutUint32(buf[0:4], pkgLen)
	n, err := conn.Write(buf[:4])
	if n != 4 || err != nil {
		fmt.Println("conn.Write() error: ", err)
		return
	}

	fmt.Println("客户端发送长度ok", len(data), string(data))

	//发送消息
	_, err = conn.Write(data)
	if err != nil {
		fmt.Println("conn.Write() error:", err)
		return
	}

	//处理服务器返回的消息

	mes, err = readPkg(conn)
	if err != nil {
		fmt.Println("readPkg mes error: ", err)
		return
	}
	//将mes里面的data反序列化成loginResMes
	var loginResMes message.LoginResMes
	err = json.Unmarshal([]byte(mes.Data), &loginResMes)

	if loginResMes.Code == 200 {
		fmt.Println("登录成功")
	} else if loginResMes.Code == 500 {
		fmt.Println(loginResMes.Error)
	}

	return
}
