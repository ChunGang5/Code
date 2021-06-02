package main

import (
	"fmt"
	"github.com/gin-gonic/gin"
	//"goLaCode/browser"
	"goLaCode/server"
	//"net/http"
	"goLaCode/controller"
)
/*type User struct {
	gorm.Model
	Name         string
	Age          sql.NullInt64
	Birthday     *time.Time
	Email        string  `gorm:"type:varchar(100);unique_index"`
	Role         string  `gorm:"size:255"` // 设置字段大小为255
	MemberNumber *string `gorm:"unique;not null"` // 设置会员号（member number）唯一并且不为空
	Num          int     `gorm:"AUTO_INCREMENT"` // 设置 num 为自增类型
	Address      string  `gorm:"index:addr"` // 给address字段创建名为addr的索引
	IgnoreMe     int     `gorm:"-"` // 忽略本字段
}*/

func main(){
	//连接数据库
	server.DataBases()
	fmt.Println("database create succeed")
	defer server.DB.Close()
	//创建默认路由
	r:=gin.Default()
	r.Static("/static","./static")
	r.LoadHTMLGlob("templates/*")
	go registerRouter(r)
	r.Run()
}

func registerRouter(router *gin.Engine){
	new(controller.LoginController).Router(router)
	new(controller.UserController).Router(router)
	new(controller.ProjectController).Router(router)
	new(controller.AchievementController).Rounter(router)
}