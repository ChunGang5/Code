package model

import "fmt"

type account struct {
	accountNo string
	balance   float64
	pwd       string
}

func NewAccount() *account {
	return &account{}
}

func (a *account) SetNo(no string) {
	if len(no) < 6 || len(no) > 10 {
		fmt.Println("input AccountNo error")
	} else {
		a.accountNo = no
	}
}

func (a *account) SetPwd(pwd string) {
	if len(pwd) != 6 {
		fmt.Println("pwd input not size is 6!")
	} else {
		a.pwd = pwd
	}
}

func (a *account) SetBalance(balance float64) {
	if balance <= 20 {
		fmt.Println("balance error")
	} else {
		a.balance = balance
	}
}

func (a *account) GetPwd() string {
	return a.pwd
}
