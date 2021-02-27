package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"strings"
)

func main() {
	conn, err := net.Dial("tcp", "192.168.31.230:8888")
	if err != nil {
		fmt.Println("client dial error ", err)
		return
	}
	fmt.Println("client dial success ", conn)
	//从标准输入读取数据
	reader := bufio.NewReader(os.Stdin) //标准输入
	for {
		//拿到读到的字符串
		line, err := reader.ReadString('\n')
		if err != nil {
			fmt.Println("读取失败：", err)
		}
		//去掉line后端的换行符
		line = strings.Trim(line, "\r\n")
		if line == "exit" {
			fmt.Println("客户端退出.....")
			break
		}
		//将读取到的数据发送给服务器
		n, err := conn.Write([]byte(line + "\n"))
		if err != nil {
			fmt.Println("conn write error ", err)
		}
		fmt.Printf("客户端发送过了%d长度的数据\n", n)
	}
}
