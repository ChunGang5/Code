package browser

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/server"
	"net/http"
)

func ChangeUserPass(ctx *gin.Context){
	fmt.Println("修改密码启动")
	oldPassword:=ctx.PostForm("mpass")
	newPassword:=ctx.PostForm("renewpass")
	//新密码两次一致前端代码已经验证过
	if oldPassword!=User.Password{
		ctx.JSON(http.StatusOK,gin.H{
			"error":"用户输入原始密码错误，请退回重新输入",
		})
	}
	server.DB.Model(User).Update("Password",newPassword)
	fmt.Println("修改密码成功")
}
