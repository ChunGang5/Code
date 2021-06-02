package controller

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/browser"
	"net/http"
	"strconv"
)
type ProjectController struct {

}

func (pro *ProjectController)Router(engine *gin.Engine){
	engine.GET("/tableproject.html",pro.GetAllProject)
	engine.GET("/leftproject.html",pro.GetLeftProject)
	engine.GET("/xmList.html",pro.GetXmList)
	engine.GET("/saveProject.html",pro.GetXSaveProject)
	engine.POST("/saveProject.html",pro.PostSaveProject)
	engine.GET("/setupProject.html",pro.GetXSetupProject)
	engine.POST("/setupProject.html",pro.PostSetupProject)
	engine.GET("/midStage.html",pro.GetMidStage)
	engine.GET("/finishStage.html",pro.GetFinishStage)
	engine.GET("/Nopassed.html",pro.GetNopassed)
	engine.GET("/ProjectDetail.html",pro.GetProjectDetail)
	engine.GET("/ProjectProcess.html",pro.GetProjectProcess)
	engine.GET("/addProject.html",pro.GetAddProject)
	engine.GET("/editorProject.html",pro.GetEditorProject)
	engine.POST("/editorProject.html",pro.PostEditorProject)
	engine.GET("/changeProjectStatus.html",pro.GetChangeProjectStatus)
	engine.POST("/changeProjectStatus.html",pro.PostChangeProjectStatus)
}

//所有项目
func (pro *ProjectController)GetAllProject(ctx *gin.Context){
	ctx.HTML(http.StatusOK,"tableproject.html",nil)
}
func (pro *ProjectController)GetLeftProject(ctx *gin.Context){
	ctx.HTML(http.StatusOK,"leftproject.html",nil)
}
func (pro *ProjectController)GetXmList(ctx *gin.Context){
	browser.GetUserProjectInfos(ctx)
	fmt.Println("获取用户所能查看的项目信息完成")
	ctx.HTML(http.StatusOK,"xmList.html",gin.H{"res":browser.Projects})
}
//申请立项项目
func (pro *ProjectController)GetXSaveProject(ctx *gin.Context){
	pid:=ctx.Query("pid")
	fmt.Printf("获取到的PID是%s\n",pid)
	if pid==""{
		browser.ApplyProject(ctx)
		ctx.HTML(http.StatusOK,"saveProject.html",gin.H{"res":browser.Projects})
	}else {
		if browser.AuthLevel==1{
			ctx.JSON(http.StatusOK,gin.H{
				"error":"普通用户无权操作！",
			})
		}else if browser.AuthLevel==2{
			_pid,_:=strconv.ParseInt(pid,10,64)
			browser.ApplyThroughProject(ctx,&_pid)
			ctx.HTML(http.StatusOK,"saveProject.html",gin.H{"res":browser.Projects})
		}
	}
}
func (pro *ProjectController)PostSaveProject(ctx *gin.Context){
	pid:=ctx.PostForm("PID")
	fmt.Printf("获取到的PID是%s\n",pid)
	if pid==""{
		browser.ApplyProject(ctx)
		ctx.HTML(http.StatusOK,"saveProject.html",gin.H{"res":browser.Projects})
	}else {
		if browser.AuthLevel==1{
			ctx.JSON(http.StatusOK,gin.H{
				"error":"普通用户无权操作！",
			})
		}else if browser.AuthLevel==2{
			_pid,_:=strconv.ParseInt(pid,10,64)
			browser.RejectApplyProject(ctx,&_pid)
			ctx.HTML(http.StatusOK,"saveProject.html",gin.H{"res":browser.Projects})
		}
	}
}
//立项阶段
func (pro *ProjectController)GetXSetupProject(ctx *gin.Context){
	browser.GetStageProject(ctx)
	ctx.HTML(http.StatusOK,"setupProject.html",gin.H{"res":browser.Projects})
}
func (pro *ProjectController)PostSetupProject(ctx *gin.Context){
	browser.GetStageProject(ctx)
	ctx.HTML(http.StatusOK,"setupProject.html",gin.H{"res":browser.Projects})
}
//中期阶段
func (pro *ProjectController)GetMidStage(ctx *gin.Context){
	fmt.Println("中期查询开始.....")
	browser.GetMidProject(ctx)

	ctx.HTML(http.StatusOK,"midStage.html",gin.H{"res":browser.Projects})
}
//结题阶段
func (pro *ProjectController)GetFinishStage(ctx *gin.Context){
	browser.GetFinishStagr(ctx)
	ctx.HTML(http.StatusOK,"finishStage.html",gin.H{"res":browser.Projects})
}
//未通过
func (pro *ProjectController)GetNopassed(ctx *gin.Context){
	browser.GetNoPassProject(ctx)
	ctx.HTML(http.StatusOK,"Nopassed.html",gin.H{"res":browser.Projects})
}

func (pro *ProjectController)GetProjectDetail(ctx *gin.Context){
	ctx.HTML(http.StatusOK,"/ProjectDetail.html",nil)
}

//项目过程
func (pro *ProjectController)GetProjectProcess(ctx *gin.Context){
	ctx.HTML(http.StatusOK,"ProjectProcess.html",nil)
}
//添加项目
func (pro *ProjectController)GetAddProject(ctx *gin.Context){
	ctx.HTML(http.StatusOK,"addProject.html",nil)
}
//
func (pro *ProjectController)GetEditorProject(ctx *gin.Context){
	if browser.AuthLevel==2{
		ctx.JSON(http.StatusOK,gin.H{
			"error":"管理人员无法申请项目",
		})
	}
	ctx.HTML(http.StatusOK,"editorProject.html",nil)
}
func (pro *ProjectController)PostEditorProject(ctx *gin.Context){
	browser.AddNewApplyProject(ctx)
	ctx.HTML(http.StatusOK,"editorProject.html",nil)
}
func (pro *ProjectController)GetChangeProjectStatus(ctx *gin.Context){
	if browser.AuthLevel==1{
		ctx.JSON(http.StatusOK,gin.H{
			"errors":"普通用户无权访问",
		})
	}else if browser.AuthLevel==2{
		ctx.HTML(http.StatusOK,"changeProjectStatus.html",nil)
	}
}
func (pro *ProjectController)PostChangeProjectStatus(ctx *gin.Context){
	pid:=ctx.PostForm("PID")
	projectStatus:=ctx.PostForm("ProjectStatus")
	concludingDate:=ctx.PostForm("ConcludingDate")
	if pid==""{
		browser.ApplyProject(ctx)
		ctx.HTML(http.StatusOK,"xmList.html",gin.H{"res":browser.Projects})
	}else {
		if browser.AuthLevel==1{
			ctx.JSON(http.StatusOK,gin.H{
				"error":"普通用户无权操作！",
			})
		} else if browser.AuthLevel==2{
				_pid,_:=strconv.ParseInt(pid,10,64)
				browser.ChangeProjectStatus(ctx,&_pid,&projectStatus,&concludingDate)
				fmt.Println("管理项目流程成功")
				ctx.HTML(http.StatusOK,"changeProjectStatus.html",nil)
				fmt.Println("渲染成功")
		}
	}
}
