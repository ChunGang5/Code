package main

import (
	"fmt"
	"progect01/Account/model"
)

func main() {
	a := model.NewAccount()
	a.SetNo("12345678")
	a.SetPwd("chenga")
	a.SetBalance(822.00)
	fmt.Println(*a)
	fmt.Println(a.GetPwd())
}
