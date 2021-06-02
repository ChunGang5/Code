package browser

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/server"
	"net/http"
	"time"
)

var Messages []server.Message
func GetMessage(ctx *gin.Context){
	fmt.Println("获取留言内容")
	if err:=server.DB.Find(&Messages).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}
	fmt.Println("获取留言内容成功")
}

func CreateMessage(ctx *gin.Context,message *string){
	MUSerName:=User.Name
	timeUnix:=time.Now().Unix()
	formatTimeStr:=time.Unix(timeUnix,0).Format("2006-01-02 15:04:05")
	DateTime:=formatTimeStr
	newMessage:=server.Message{
		MUserName: MUSerName,
		DateTime:  DateTime,
		Content:   *message,
	}
	server.DB.Create(&newMessage)
	if err:=server.DB.Find(&Messages).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}
}