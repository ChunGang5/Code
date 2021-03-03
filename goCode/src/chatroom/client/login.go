package main

import (
	"fmt"
)

func login(userId string, userPwd string) (err error) {
	//定协议
	fmt.Printf("userId=%s, userPwd=%s\n", userId, userPwd)
	return nil
}
