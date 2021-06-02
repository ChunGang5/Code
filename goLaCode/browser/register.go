package browser

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/server"
	"net/http"
	"strconv"
	"github.com/jinzhu/gorm"
)

func Register(ctx *gin.Context){
	userId,err:=strconv.ParseInt(ctx.PostForm("Id"),10,64)
	passWord:=ctx.PostForm("password")
	fmt.Printf("Register get userName : %d    passWord : %s\n",userId,passWord)
	var user server.User
	err=server.DB.Where("ID=?",userId).First(&user).Error
	if err==gorm.ErrRecordNotFound{
		user=server.User{
			userId,
			passWord,
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			server.Authority{},
			1,
		}
		fmt.Println("Register create :.......")
		fmt.Println(server.DB.NewRecord(&user))
		server.DB.Create(&user)
		fmt.Println(server.DB.NewRecord(&user))
		return
	}
	if err==nil{
		ctx.JSON(http.StatusOK,gin.H{"error":"该用户已存在"})
		return
	}
	if err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":err.Error()})
		return
	}

	//数据库不存在该用户

}