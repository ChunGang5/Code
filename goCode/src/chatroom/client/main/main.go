package main

import (
	"chatroom/client/process"
	"fmt"
	"os"
)

var userId int
var userPwd string
var userName string

func main() {
	//接收用户选择
	var key int

	for true {
		fmt.Println("----------欢迎来到多人网络聊天室----------")
		fmt.Println("\t 1.登录聊天室")
		fmt.Println("\t 2.用户注册")
		fmt.Println("\t 3.exit")
		fmt.Println("\t 请选择1-3")

		fmt.Scanf("%d\n", &key)
		switch key {
		case 1:
			fmt.Println("登录聊天室")
			fmt.Println("请输入用户的id")
			fmt.Scanf("%d\n", &userId)
			fmt.Println("请输入用户的密码")
			fmt.Scanf("%s\n", &userPwd)
			//创建一个userProcess实例
			up := &process.UserProcess{}
			up.Login(userId, userPwd)
		case 2:
			fmt.Println("用户注册")
			fmt.Println("请输入用户ID")
			fmt.Scanf("%d\n",&userId)
			fmt.Println("请输入密码")
			fmt.Scanf("%s\n",&userPwd)
			fmt.Println("请输入用户名")
			fmt.Scanf("%s\n",&userName)
			up:=&process.UserProcess{}
			up.Register(userId,userPwd,userName)

		case 3:
			fmt.Println("exit")
			os.Exit(0)
		default:
			fmt.Println("输入有误，请重新输入")
		}
	}

	// if key == 1 {
	// 	fmt.Println("请输入用户的id")
	// 	fmt.Scanf("%d\n", &userId)
	// 	fmt.Println("请输入用户的密码")
	// 	fmt.Scanf("%s\n", &userPwd)
	// 	login(userId, userPwd)
	// 	// if err != nil {
	// 	// 	fmt.Println("用户注册失败：", err)
	// 	// } else {
	// 	// 	fmt.Println("登录成功")
	// 	// }
	// } else if key == 2 {
	// 	fmt.Println("用户注册")
	// }
}
