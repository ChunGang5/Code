package process2

import (
	"chatroom/common/message"
	"chatroom/server/model"
	"chatroom/server/utils"
	"encoding/json"
	"fmt"
	"net"
)

type UserProcess struct {
	Conn   net.Conn
	UserId int //表明是哪个用户得Process
}

func (this *UserProcess) ServerProcessLogin(mes *message.Message) (err error) {
	//先从mes中取出mes.data,将其反序列化，之前反序列化一次的只是将message反序列了
	var loginMes message.LoginMes
	err = json.Unmarshal([]byte(mes.Data), &loginMes)
	if err != nil {
		fmt.Println("mes.data json.Unmarshal error: ", err)
		return
	}
	//编写返回的协议包
	var resMes message.Message
	resMes.Type = message.LoginResMesType
	//声明一个loginResMes
	var loginResMes message.LoginResMes

	user, err := model.MyUserDao.Login(loginMes.UserId, loginMes.UserPwd)
	if err != nil {
		if err == model.ERROR_USER_NOTEXIST {
			loginResMes.Code = 500
			loginResMes.Error = err.Error()
		} else if err == model.ERROR_USER_RWD {
			loginResMes.Code = 403 //密码errror
			loginResMes.Error = err.Error()
		} else {
			loginResMes.Code = 505
			loginResMes.Error = "服务器端错误"
		}

	} else {
		loginResMes.Code = 200
		fmt.Println(user, "登录成功")
		//将该登录成功得用户放入userMgr,并将userID放入
		this.UserId = loginMes.UserId
		userMgr.AddOnlineUser(this)
		//通知其他在线用户我上线了
		this.NotifyOthersOnlineUser(loginMes.UserId)
		//遍历onlineusers，放入
		for id, _ := range userMgr.onlineUsers {
			loginResMes.UsersId = append(loginResMes.UsersId, id)
		}
	}

	// if loginMes.UserId == 100 && loginMes.UserPwd == "12345" {
	// 	//存在
	// 	loginResMes.Code = 200
	// 	loginResMes.Error = "登录成功"
	// } else {
	// 	loginResMes.Code = 500
	// 	loginResMes.Error = "该用户不存在，请先注册再登录"
	// }

	//将loginResMes先序列化，并赋给resMes,在发送给客户端
	data, err := json.Marshal(loginResMes)
	if err != nil {
		fmt.Println("loginResMes marshal error: ", err)
		return
	}

	resMes.Data = string(data)

	data, err = json.Marshal(resMes)
	if err != nil {
		fmt.Println("resMes marshal error: ", err)
		return
	}
	//发送,writePkg函数

	tf := &utils.Transfer{
		Conn: this.Conn,
	}

	err = tf.WritePkg(data)
	return
}

func (this *UserProcess) ServerProcessRegister(mes *message.Message) (err error) {
	var registerMes message.RegisterMes
	err = json.Unmarshal([]byte(mes.Data), &registerMes)
	if err != nil {
		fmt.Println("mes.data json.Unmarshal error: ", err)
		return
	}

	//编写返回的协议包
	var resMes message.Message
	resMes.Type = message.RegisterResMesType
	//声明一个RegisterResMes
	var registerResMes message.RegisterResMes
	//去redis完成验证
	err = model.MyUserDao.Register(&registerMes.User)
	if err != nil {
		if err == model.ERROR_USER_EXIST {
			registerResMes.Code = 505
			registerResMes.Error = model.ERROR_USER_EXIST.Error()
		} else {
			registerResMes.Code = 506
			registerResMes.Error = "注册发生未知错误"
		}
	} else {
		registerResMes.Code = 200
	}

	//将loginResMes先序列化，并赋给resMes,在发送给客户端
	data, err := json.Marshal(registerResMes)
	if err != nil {
		fmt.Println("registerResMes marshal error: ", err)
		return
	}

	resMes.Data = string(data)

	data, err = json.Marshal(resMes)
	if err != nil {
		fmt.Println("resMes marshal error: ", err)
		return
	}
	//发送,writePkg函数

	tf := &utils.Transfer{
		Conn: this.Conn,
	}

	err = tf.WritePkg(data)
	return
}

//g给用户通知有人上线了，
func (this *UserProcess) NotifyMeOnline(userId int) {
	var mes message.Message
	mes.Type = message.NotifyUserStatusMesType
	var notifyUserStatusMes message.NotifyUserStatusMes
	notifyUserStatusMes.UserId = userId
	notifyUserStatusMes.UserStatus = message.UserOnline //表示用户上线
	//序列花后发送
	data, err := json.Marshal(notifyUserStatusMes)
	if err != nil {
		fmt.Println("json Marshal error: ", err)
		return
	}
	mes.Data = string(data)

	data, err = json.Marshal(mes)
	if err != nil {
		fmt.Println("json Marshal error: ", err)
		return
	}

	tf := &utils.Transfer{
		Conn: this.Conn,
	}
	err = tf.WritePkg(data)
	if err != nil {
		fmt.Println("NotufyMeOnline error: ", err)
	}

}

//一个用户上线以后，要通知其他已经上线的用户,
func (this *UserProcess) NotifyOthersOnlineUser(userId int) {
	for id, up := range userMgr.onlineUsers {
		//不用发给自己
		if id == userId {
			continue
		}
		up.NotifyMeOnline(userId)
	}
}
