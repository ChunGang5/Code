package controller

import (
	"github.com/gin-gonic/gin"
	"goLaCode/browser"
	"net/http"
	"fmt"
)

type UserController struct {

}

func (user *UserController)Router(engine *gin.Engine){
	engine.GET("/pass.html",user.UserPass)
	engine.POST("/pass.html",user.PostUserPass)
	engine.GET("/personnew.html",user.ShowUserInfo)
	engine.POST("/personnew.html",user.PostPersonnew)
}
func (user *UserController)UserPass(ctx *gin.Context){
	fmt.Println(browser.User.Name)
	ctx.HTML(http.StatusOK,"pass.html",gin.H{
		"Name":browser.User.Name,
	})
}
//修改用户密码
func (User *UserController)PostUserPass(ctx *gin.Context) {
	browser.ChangeUserPass(ctx)
	ctx.HTML(http.StatusOK,"pass.html",nil)
}
func (user *UserController)ShowUserInfo(ctx *gin.Context){
	ctx.HTML(http.StatusOK,"personnew.html",gin.H{
		"Id":browser.User.ID,
		"Name":browser.User.Name,
		"Position":browser.User.Position,
		"Graduate_institutions":browser.User.GraduateInstitutions,
		"Sex":browser.User.Sex,
		"Hiredate":browser.User.Hiredate,
		"Degree":browser.User.Degree,
		"Birth_time":browser.User.BirthTime,
		"Department":browser.User.Department,
		"Telephone":browser.User.Telephone,
		"Email":browser.User.Email,
		"Politic_status":browser.User.PoliticStatus,
		"Education_background":browser.User.EducationBackground,
		"Address":browser.User.Address,
	})
}

func (user *UserController)PostPersonnew(ctx *gin.Context){
	browser.ChangeUserInfo(ctx)
	ctx.HTML(http.StatusOK,"personnew.html",nil)
}