package process

import (
	"chatroom/client/utils"
	"chatroom/common/message"
	"encoding/json"
	"fmt"
	"net"
	"os"
)

func ShowMenu() {
	fmt.Println("----------恭喜您登录成功----------")
	fmt.Println("----------1.显示在线用户列表------")
	fmt.Println("----------2.发送消息-------------")
	fmt.Println("----------3.信息列表-------------")
	fmt.Println("----------4.退出-----------------")
	fmt.Println("----------请选择:1-4-------------")
	var key int
	var content string
	//创建一个smeProcess实例
	smsProcess := &SmsProcess{}
	fmt.Scanf("%d\n", &key)
	switch key {
	case 1:
		fmt.Println("显示在线用户列表")
		showOnlineUsers()
	case 2:
		fmt.Println("请输入要发送的消息")
		fmt.Scanf("%s\n", &content)
		smsProcess.SendGroupMes(content)
	case 3:
		fmt.Println("信息列表")
	case 4:
		fmt.Println("退出")
		os.Exit(0)
	default:
		fmt.Println("没有此选项，请重新输入")
	}
}

//保持和服务器端的通信
func serverProcessMes(conn net.Conn) {
	tf := &utils.Transfer{
		Conn: conn,
	}
	for {
		fmt.Println("客户端正在等到读取服务端发送的消息")
		mes, err := tf.ReadPkg()
		if err != nil {
			fmt.Println("tf.Read error: ", err)
			return
		}
		//读到什么类型就选择什么方法处理
		switch mes.Type {
		case message.NotifyUserStatusMesType:
			//通知有人上线了
			//1、先取出来NotifyUserStatusMes
			var notifyUserStatusMes message.NotifyUserStatusMes
			json.Unmarshal([]byte(mes.Data), &notifyUserStatusMes)
			//更新client端map
			updateUserStatus(&notifyUserStatusMes)
		case message.SmsMesType:
			showGroupMes(&mes)
		default:
			fmt.Println("服务器端返回了一个未知类型的消息")

		}
		fmt.Printf("mes=%v ", mes)
	}
}
