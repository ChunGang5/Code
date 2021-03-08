package process

import (
	"chatroom/client/utils"
	"chatroom/common/message"
	"encoding/binary"
	"encoding/json"
	"fmt"
	"net"
	"os"
)

type UserProcess struct {
}

func (this *UserProcess) Login(userId int, userPwd string) (err error) {
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

	tf := &utils.Transfer{
		Conn: conn,
	}
	mes, err = tf.ReadPkg()
	if err != nil {
		fmt.Println("readPkg mes error: ", err)
		return
	}
	//将mes里面的data反序列化成loginResMes
	var loginResMes message.LoginResMes
	err = json.Unmarshal([]byte(mes.Data), &loginResMes)

	if loginResMes.Code == 200 {
		//fmt.Println("登录成功")
		//初始化CurUser
		CurUser.Conn=conn
		CurUser.UserId=userId
		CurUser.UserStatus=message.UserOnline

		//show当前用户列表
		fmt.Println("在线用户列表如下...")
		for _, v := range loginResMes.UsersId {

			fmt.Println("用户id:\t", v)
			//完成客户端的onlineUsers（map）的初始化
			user := &message.User{
				UserId:     v,
				UserStatus: message.UserOnline,
			}
			onlineUsers[v] = user
		}
		fmt.Print("\n\n\n")
		//起一个协程以保持和服务器的通信，确保收到服务器发送的消息，因为登录成功用户在操作的时候可能会收到其他人给的消息
		//很重要的一个协程
		go serverProcessMes(conn)
		//显示登录成功的二级菜单
		for {
			ShowMenu()
		}
	} else {
		fmt.Println(loginResMes.Error)
	}

	return
}

func (this *UserProcess) Register(userId int, userPwd string, userName string) (err error) {
	conn, err := net.Dial("tcp", "localhost:8888")
	if err != nil {
		fmt.Println("net.Dial error: ", err)
		return
	}
	defer conn.Close()

	//准备通过conn将消息发送出去，先组织消息
	var mes message.Message
	mes.Type = message.RegisterMesType
	//创建一个loginMes结构体
	var registerMes message.RegisterMes
	registerMes.User.UserId = userId
	registerMes.User.UserPwd = userPwd
	registerMes.User.UserName = userName

	data, err := json.Marshal(registerMes)
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

	tf := &utils.Transfer{
		Conn: conn,
	}
	err = tf.WritePkg(data)
	if err != nil {
		fmt.Println("register write error: ", err)
		return
	}
	mes, err = tf.ReadPkg()
	if err != nil {
		fmt.Println("readpkg error: ", err)
		return
	}

	//将mes里面的data反序列化成registerResMes
	var registerResMes message.RegisterResMes
	err = json.Unmarshal([]byte(mes.Data), &registerResMes)

	if registerResMes.Code == 200 {
		fmt.Println("注册成功，请重新登录")
		os.Exit(0)
	} else {
		fmt.Println(registerResMes.Error)
		os.Exit(0)
	}
	return

}
