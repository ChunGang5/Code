package process2

import (
	"fmt"
)

var (
	userMgr *UserMgr
)

//维护一个map用来表示哪个用户上线了
type UserMgr struct {
	onlineUsers map[int]*UserProcess
}

func init() {
	userMgr = &UserMgr{
		onlineUsers: make(map[int]*UserProcess, 1024),
	}

}

//增加
func (this *UserMgr) AddOnlineUser(up *UserProcess) {
	this.onlineUsers[up.UserId] = up

}

//删除
func (this *UserMgr) DeleteOnlineUser(userId int) {
	delete(this.onlineUsers, userId)
}

//查询
func (this *UserMgr) GetAllOnlineUser() map[int]*UserProcess {
	return this.onlineUsers
}

//根据id返回一个对应的userProcess，点对点聊天
func (this *UserMgr) GetOnlineUserById(userId int) (up *UserProcess, err error) {
	up, ok := this.onlineUsers[userId]
	if !ok {
		//查找的这个用户不在线
		err = fmt.Errorf("用户%d不存在", userId)
		return
	} else {
		return
	}
}
