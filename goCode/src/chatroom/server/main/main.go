package main

import (
	//"chatroom/common/message"
	//"encoding/binary"
	//"encoding/json"
	"chatroom/server/model"
	"fmt"
	"net"
	"time"
)

// //处理客户端发送过来的数据
// func readPkg(conn net.Conn) (mes message.Message, err error) {
// 	buf := make([]byte, 8096)
// 	fmt.Println("读取客户端发送的消息.....")
// 	_, err = conn.Read(buf[:4])
// 	if err != nil {
// 		//err = errors.New("read pkg header error")
// 		//fmt.Println("conn.Read() error: ", err)
// 		return
// 	}

// 	var pkgLen uint32
// 	pkgLen = binary.BigEndian.Uint32(buf[0:4])
// 	//根据pkgLen读取数据
// 	n, err := conn.Read(buf[:pkgLen])
// 	if n != int(pkgLen) || err != nil {
// 		return
// 	}

// 	//再将读到的消息反序列化->message.Message
// 	err = json.Unmarshal(buf[:pkgLen], &mes)
// 	if err != nil {
// 		//err = errors.New("read pkg body error")
// 		fmt.Println("json.Unmarshal() error: ", err)
// 		return
// 	}
// 	return
// }

// //将服务器端处理后的数据，发怂给客户端
// func writePkg(conn net.Conn, data []byte) (err error) {
// 	var pkgLen uint32
// 	pkgLen = uint32(len(data))
// 	var buf [4]byte //开辟4int8长度的数组/切片
// 	//将pkgLen转换为uint32位的大端，网络上跑的都是大端数据
// 	binary.BigEndian.PutUint32(buf[0:4], pkgLen)
// 	//发送长度
// 	n, err := conn.Write(buf[:4])
// 	if n != 4 || err != nil {
// 		fmt.Println("conn.Write error: ", err)
// 		return
// 	}

// 	//发送data
// 	n, err = conn.Write(data)
// 	if n != int(pkgLen) || err != nil {
// 		fmt.Println("data write error: ", err)
// 		return
// 	}
// 	return

// }

//专门处理登录请求的函数
// func serverProcessLogin(conn net.Conn, mes *message.Message) (err error) {
// 	//先从mes中取出mes.data,将其反序列化，之前反序列化一次的只是将message反序列了
// 	var loginMes message.LoginMes
// 	err = json.Unmarshal([]byte(mes.Data), &loginMes)
// 	if err != nil {
// 		fmt.Println("mes.data json.Unmarshal error: ", err)
// 		return
// 	}
// 	//编写返回的协议包
// 	var resMes message.Message
// 	resMes.Type = message.LoginResMesType
// 	//声明一个loginResMes
// 	var loginResMes message.LoginResMes

// 	if loginMes.UserId == 100 && loginMes.UserPwd == "12345" {
// 		//存在
// 		loginResMes.Code = 200
// 		loginResMes.Error = "登录成功"
// 	} else {
// 		loginResMes.Code = 500
// 		loginResMes.Error = "该用户不存在，请先注册再登录"
// 	}

// 	//将loginResMes先序列化，并赋给resMes,在发送给客户端
// 	data, err := json.Marshal(loginResMes)
// 	if err != nil {
// 		fmt.Println("loginResMes marshal error: ", err)
// 		return
// 	}

// 	resMes.Data = string(data)

// 	data, err = json.Marshal(resMes)
// 	if err != nil {
// 		fmt.Println("resMes marshal error: ", err)
// 		return
// 	}
// 	//发送,writePkg函数
// 	err = writePkg(conn, data)
// 	return
// }

// //根据客户端发送过来的消息不同，来觉得调用哪个函数来进行处理
// func serverProcessMes(conn net.Conn, mes *message.Message) (err error) {
// 	switch mes.Type {
// 	case message.LoginMesType:
// 		//处理登录请求
// 		serverProcessLogin(conn, mes)
// 	case message.RegisterMesType:
// 		//处理注册请求
// 	default:
// 		fmt.Println("此消息类型不存在，无法进行处理.....")
// 	}
// 	return
// }
func process(conn net.Conn) {
	defer conn.Close()

	processor := &Processor{
		Conn: conn,
	}
	err := processor.processLast()
	if err != nil {
		fmt.Println("客户端和服务器端通信出错：", err)
		return
	}
}
func init() {
	//初始化redis连接池
	initPool("localhost:6379", 16, 0, 100*time.Second)
	initUserDao()
}
func initUserDao() {
	//用的是redis.go里面的全局变量pool
	model.MyUserDao = model.NewUserDao(pool)
}
func main() {

	fmt.Println("服务器启动，端口号8888")
	listen, err := net.Listen("tcp", "127.0.0.1:8888")
	if err != nil {
		fmt.Println("服务器listen error: ", err)
		return
	}

	for {
		fmt.Println("等待客户端前来连接.....")
		conn, err := listen.Accept()
		if err != nil {
			fmt.Println("accept error: ", err)
		}
		go process(conn)
	}
}
