package main

import (
	"fmt"
	"net"
)

func process(conn net.Conn) {
	defer conn.Close()
	for {
		//创建一个新的切片
		buf := make([]byte, 1024)
		//等待客户端通过conn发送信息，如果客户端没有weite发送过来，那么协程就阻塞在这里
		fmt.Printf("服务器等待客户端%s发送信息\n", conn.RemoteAddr().String())
		n, err := conn.Read(buf)
		if err != nil {
			fmt.Println("服务器端read错误，err= ", err)
			return
		}
		fmt.Println(string(buf[:n]))
	}

}
func main() {
	fmt.Println("服务器开始监听·····")
	listen, err := net.Listen("tcp", "0.0.0.0:8888")
	if err != nil {
		fmt.Println("listen error, ", err)
		return
	}
	defer listen.Close()
	for {
		fmt.Println("等待客户端连接")
		conn, err := listen.Accept()
		if err != nil {
			fmt.Println("Accept error ", err)
		} else {
			fmt.Printf("Accpet success conn=%v  客户端 ip=%v\n", conn, conn.RemoteAddr().String())
		}
		go process(conn)
	}
}
