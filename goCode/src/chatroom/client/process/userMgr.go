package process

import (
	"chatroom/client/model"
	"chatroom/common/message"
	"fmt"
)

//管理客户端的user，维护一个map
var onlineUsers map[int]*message.User = make(map[int]*message.User, 10)

var CurUser model.CurUser

//显示当前在线用户
func showOnlineUsers() {
	fmt.Println("当前在线用户列表：")
	for id, _ := range onlineUsers {
		fmt.Println("用户id:\t", id)
	}
}

func updateUserStatus(notifyUserStatusMes *message.NotifyUserStatusMes) {
	user, ok := onlineUsers[notifyUserStatusMes.UserId]
	if !ok {
		//原map中没有,创建
		user = &message.User{
			UserId: notifyUserStatusMes.UserId,
		}
	}
	//原map中有只是更新
	user.UserStatus = notifyUserStatusMes.UserStatus
	onlineUsers[notifyUserStatusMes.UserId] = user
	showOnlineUsers()
}
