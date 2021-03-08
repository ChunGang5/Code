package model

import (
	"chatroom/common/message"
	"net"
)

//获取自己本身的信息
type CurUser struct {
	Conn net.Conn
	message.User
}
