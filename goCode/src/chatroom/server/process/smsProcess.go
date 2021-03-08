package process2

import (
	"chatroom/common/message"
	"chatroom/server/utils"
	"encoding/json"
	"fmt"
	"net"
)

type SmsProcess struct {
}

func (this *SmsProcess) SendGroupMes(mes *message.Message) {
	var smsMes message.SmsMes
	err := json.Unmarshal([]byte(mes.Data), smsMes)
	if err != nil {
		fmt.Println("smsMes Unmarshal error: ", err)
		return
	}

	data, err := json.Marshal(mes)
	if err != nil {
		fmt.Println("json Marshal error: ", err)
		return
	}
	//遍历onlineUsers，将消息发送出去
	for id, up := range userMgr.onlineUsers {
		if id == smsMes.UserId {
			continue
		}
		this.SendMesToEnchOnlineUser(data, up.Conn)
	}
}

//将消息发送出去
func (this *SmsProcess) SendMesToEnchOnlineUser(data []byte, conn net.Conn) {
	tf := &utils.Transfer{
		Conn: conn,
	}
	err := tf.WritePkg(data)
	if err != nil {
		fmt.Println("转发消息失败: ", err)
	}
}
