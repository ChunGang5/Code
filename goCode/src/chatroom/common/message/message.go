package message

const (
	LoginMesType       = "LoginMes"
	LoginResMesType    = "LoginResMes"
	RegisterMesType    = "RegisterMes"
	RegisterResMesType = "RegisterResMes"
	NotifyUserStatusMesType="NotifyUserStatusMes"
	SmsMesType="SmsMes"
)
//定义用户状态常量
const (
	UserOnline=iota		//上线	0
	UserOffline			//下线	1	
	UserBusyStatus		//繁忙	2
)

type Message struct {
	Type string `json:"type"` //消息类型
	Data string `json:"data"` //消息的类型
}

type LoginMes struct {
	UserId   int    `json:"userId"`   //用户id
	UserPwd  string `json:"userPwd"`  //用户密码
	UserName string `json:"userName"` //用户名
}

type LoginResMes struct {
	Code    int    `json:"code"`  //返回码
	Error   string `json:"error"` //返回的错误消息
	UsersId []int  //增加一个在线用户id的切片，方便服务器告知客户端在线用户有谁
}

type RegisterMes struct {
	User User `json:"user"`
}

type RegisterResMes struct {
	Code  int    `json:"code"` //500表示未注册，200	登录成功
	Error string `json:"erroe"`
}


type NotifyUserStatusMes struct{
	UserId int `json:"userId"`
	UserStatus int `json:"userStatu"`
}

type SmsMes struct{
	Content string `json:"contene"`	//消息内容
	User	//以继承方式
}