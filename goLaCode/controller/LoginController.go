package controller

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/browser"
	"net/http"
)

type LoginController struct {

}
func (login *LoginController)Router(engine *gin.Engine){
	engine.GET("/login.html",login.GetLogin)
	engine.POST("/login.html",login.Login)
	engine.GET("/info.html",login.ShowNoticeInfo)
	engine.GET("/register.html",login.GetRegister)
	engine.POST("/register.html",login.PostRegister)
	engine.GET("/download.html",login.GetDownload)
	engine.GET("/cate.html",login.GetCate)
	engine.POST("/cate.html",login.PostCate)
}
//展示主页公告信息
func (login *LoginController)ShowNoticeInfo(ctx *gin.Context){
	ctx.HTML(http.StatusOK,"info.html",nil)
}
func (login *LoginController)GetLogin(context *gin.Context){
	context.HTML(http.StatusOK,"login.html",nil)
	fmt.Println("Login get调用成功")
}
func (login *LoginController)Login(context *gin.Context){
	//context.HTML(http.StatusOK,"login.html",nil)
	fmt.Println("Login Post调用成功")
	//browser.Login(context)
	/*if *browser.Err!=nil{
		return
	}*/err:=browser.Login(context)
	if err!=nil{
		return
	}
	browser.GetAthuLevel(context)
	context.HTML(http.StatusOK,"index.html",nil)
}
func (login *LoginController)Index(context *gin.Context){
	context.HTML(http.StatusOK,"index.html",nil)
}
//注册界面
func (login *LoginController)GetRegister(ctx *gin.Context){
	fmt.Println("GetRegister调用成功")
	ctx.HTML(http.StatusOK,"register.html",nil)
}
func (login *LoginController)PostRegister(ctx *gin.Context){
	fmt.Println("PostRegister调用成功")
	browser.Register(ctx)
	ctx.HTML(http.StatusOK,"login.html",nil)
}
func (login *LoginController)GetDownload(ctx *gin.Context){
	//ctx.Header("Content-Type","application/zip")
	//
	// ctx.Header("Content-Disposition", fileContentDisposition)
	ctx.HTML(http.StatusOK,"download.html",nil)
}
func (login *LoginController)PostDownLoad(ctx *gin.Context){

}
func (login *LoginController)GetCate(ctx *gin.Context){
	browser.GetMessage(ctx)
	ctx.HTML(http.StatusOK,"cate.html",gin.H{"res":browser.Messages})
}
func (login *LoginController)PostCate(ctx *gin.Context){
	message:=ctx.PostForm("Message")
	if message==""{
		ctx.HTML(http.StatusOK,"cate.html",gin.H{"res":browser.Messages})
	}else{
		browser.CreateMessage(ctx,&message)
		ctx.HTML(http.StatusOK,"cate.html",gin.H{"res":browser.Messages})
	}
}