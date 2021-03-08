package model

import (
	"chatroom/common/message"
	"encoding/json"
	"fmt"

	"github.com/garyburd/redigo/redis"
)

var (
	MyUserDao *UserDao
)

//定义一个UserDao结构体，用来管理
type UserDao struct {
	pool *redis.Pool
}

func NewUserDao(pool *redis.Pool) (userDao *UserDao) {
	userDao = &UserDao{
		pool: pool,
	}
	return
}

func (this *UserDao) getUserById(conn redis.Conn, id int) (user *User, err error) {
	res, err := redis.String(conn.Do("HGET", "users", id))
	if err != nil {
		if err == redis.ErrNil {
			//users在哈希中，没有找的对应的id
			err = ERROR_USER_NOTEXIST
		}
		return
	}
	user = &User{}
	//将res反序列化为user实例
	err = json.Unmarshal([]byte(res), &user)
	if err != nil {
		fmt.Println("json Unmarshal error: ", err)
		return
	}
	return
}

//拿到user信息以后开始完成id和pwd的校验
func (this *UserDao) Login(userId int, userPwd string) (user *User, err error) {
	//从redis的连接池里取出一个连接
	conn := this.pool.Get()
	defer conn.Close()
	//从redis里取出id对应得user信息
	user, err = this.getUserById(conn, userId)
	if err != nil {
		return
	}
	//pwd验证
	if user.UserPwd != userPwd {
		err = ERROR_USER_RWD
		return
	}
	return
}

func (this *UserDao) Register(user *message.User) (err error) {
	//从redis的连接池里取出一个连接
	conn := this.pool.Get()
	defer conn.Close()
	//从redis里取出id对应得user信息
	_, err = this.getUserById(conn, user.UserId)
	if err == nil {
		//该用户注册过
		err = ERROR_USER_EXIST
		return
	}
	//redis里没有该用户，入库注册
	data, err := json.Marshal(user) //序列化
	if err != nil {
		return
	}
	_, err = conn.Do("HSET", "users", user.UserId, string(data))
	if err != nil {
		fmt.Println("保存注册用户信息失败：", err)
		return
	}
	return
}
