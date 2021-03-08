package message

type User struct {
	//为了能够序列化和反序列化成功，必须要tag一下，用户信息的key和User的字段必须保持一致，用户信息该开始写成小写的了
	UserId   int    `json:"userId"`
	UserPwd  string `json:"userPwd"`
	UserName string `json:"userName"`
	UserStatus int `json:"userStatus"`//用户状态 0、1、2等？
}
