package process

import (
	"chatroom/common/message"
	"encoding/json"
	"fmt"
)

func showGroupMes(mes *message.Message) {
	var smsMes message.SmsMes
	err := json.Unmarshal([]byte(mes.Data), &smsMes)
	if err != nil {
		fmt.Println("json Unmarshal error: ", err)
		return
	}

	//显示
	info := fmt.Sprintf("用户id:\t%d 发来消息:\t%s", smsMes.UserId, smsMes.Content)
	fmt.Println(info)
	fmt.Println()
}
