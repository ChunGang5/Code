package main

import (
	"chatroom/common/message"
	process2 "chatroom/server/process"
	"chatroom/server/utils"
	"fmt"
	"io"
	"net"
)

type Processor struct {
	Conn net.Conn
}

//根据客户端发送过来的消息不同，来觉得调用哪个函数来进行处理
func (this *Processor) serverProcessMes(mes *message.Message) (err error) {
	//测试
	//fmt.Println("mes=: ", mes)

	switch mes.Type {
	case message.LoginMesType:
		//处理登录请求
		up := &process2.UserProcess{
			Conn: this.Conn,
		}
		err = up.ServerProcessLogin(mes)
	case message.RegisterMesType:
		//处理注册请求
		up := &process2.UserProcess{
			Conn: this.Conn,
		}
		err = up.ServerProcessRegister(mes)
	case message.SmsMesType:
		smsProcess:=&Process2.SmsProcess
		smsProcess.SendGroupMes(mes)
	default:
		fmt.Println("此消息类型不存在，无法进行处理.....")
	}
	return
}

func (this *Processor) processLast() (err error) {
	//循环读客户端发送的消息
	//创建Transfer实例来读数据
	for {
		tf := &utils.Transfer{
			Conn: this.Conn,
		}
		mes, err := tf.ReadPkg()
		if err != nil {
			if err == io.EOF {
				fmt.Println("客户端退出，服务端也退出.....")
				return err
			} else {
				fmt.Println("readpkg err:", err)
				return err
			}
		}
		//fmt.Println("mes= ", mes)
		err = this.serverProcessMes(&mes)
		if err != nil {
			return err
		}
	}
}
