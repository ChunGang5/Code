package controller

import (
	"github.com/gin-gonic/gin"
	"goLaCode/browser"
	"net/http"
	"strconv"
)

type AchievementController struct {

}
func (ach *AchievementController)Rounter(engine *gin.Engine){
	engine.GET("/listpaper.html",ach.GetPaper)
	engine.POST("listpaper.html",ach.PostPaper)
	engine.GET("/addpaper.html",ach.GetAddPaper)
	engine.GET( "/addreward.html",ach.GetAaddReward)
	engine.POST("/addpaper.html",ach.PostAddPaper)
	engine.GET("/listthings.html",ach.GetThings)
	engine.POST("/listthings.html",ach.PostThings)
	engine.GET("/addthings.html",ach.GetNewThings)
	engine.POST("/addthings.html",ach.PostAddThing)
	engine.GET("/listpatent.html",ach.GetPatent)
	engine.POST("/listpatent.html",ach.PostPatent)
	engine.GET("/addpatent.html",ach.GetAddPatent)
	engine.POST("/addpatent.html",ach.PostAddPatent)
}
//论文
func (ach *AchievementController)GetPaper(ctx *gin.Context){
	accessionNum:=ctx.Query("AccessionNum")
	if accessionNum==""{
		browser.GetPeriodicalInfo(ctx)
		ctx.HTML(http.StatusOK,"listpaper.html",gin.H{"res":browser.Periodicals})
	}else{
		if browser.AuthLevel==1{
			ctx.JSON(http.StatusOK,gin.H{
				"error":"普通用户无权操作！",
			})
		}else if browser.AuthLevel==2{
			_accessionNum,_:=strconv.ParseInt(accessionNum,10,64)
			browser.CheckPeriocals(ctx,&_accessionNum)
			browser.GetPerizeInfo(ctx)
			ctx.HTML(http.StatusOK,"listpaper.html",gin.H{"res":browser.Periodicals})
		}
	}

}
func (ach *AchievementController)PostPaper(ctx *gin.Context){
	if browser.AuthLevel==1{
		ctx.JSON(http.StatusOK,gin.H{
			"error":"普通用户无权操作！",
		})
	}else if browser.AuthLevel==2{
		accessionNum:=ctx.PostForm("AccessionNum")
		if accessionNum==""{
			ctx.HTML(http.StatusOK,"listpaper.html",gin.H{"res":browser.Periodicals})
		}else {
			_accessionNum,_:=strconv.ParseInt(accessionNum,10,64)
			browser.DeletePeriocals(ctx,&_accessionNum)
			ctx.HTML(http.StatusOK,"listpaper.html",gin.H{"res":browser.Periodicals})
		}
	}
}
func (ach *AchievementController)GetAddPaper(ctx *gin.Context){
	if browser.AuthLevel==2{
		ctx.JSON(http.StatusOK,gin.H{
			"error":"管理人员无权操作！",
		})
	}else if browser.AuthLevel==1{
		ctx.HTML(http.StatusOK,"addpaper.html",nil)
	}
}
func (ach *AchievementController)PostAddPaper(ctx *gin.Context){
	browser.AddPeriodical(ctx)
	ctx.HTML(http.StatusOK,"addpaper.html",nil)
}
func (ach *AchievementController)GetAaddReward(ctx *gin.Context){
	ctx.HTML(http.StatusOK, "addreward.html",nil)
}

//获奖
func (ach *AchievementController)GetThings(ctx *gin.Context){
	prizeID:=ctx.Query("PrizeID")
	if prizeID==""{
		browser.GetPerizeInfo(ctx)
		ctx.HTML(http.StatusOK,"listthings.html",gin.H{"res":browser.Prizes})
	}else{
		if browser.AuthLevel==1{
			ctx.JSON(http.StatusOK,gin.H{
				"error":"普通用户无权操作！",
			})
		}else if browser.AuthLevel==2{
			_prizeID,_:=strconv.ParseInt(prizeID,10,64)
			browser.CheckPrize(ctx,&_prizeID)
			browser.GetPerizeInfo(ctx)
			ctx.HTML(http.StatusOK,"listthings.html",gin.H{"res":browser.Prizes})
		}
	}
}
func (ach *AchievementController)PostThings(ctx *gin.Context){
	if browser.AuthLevel==1{
		ctx.JSON(http.StatusOK,gin.H{
			"error":"普通用户无权操作！",
		})
	}else if browser.AuthLevel==2{
		prizeID:=ctx.PostForm("PrizeID")
		if prizeID==""{
			ctx.HTML(http.StatusOK,"listthings.html",gin.H{"res":browser.Prizes})
		}else {
			_prizeID,_:=strconv.ParseInt(prizeID,10,64)
			browser.DeletePrize(ctx,&_prizeID)
			ctx.HTML(http.StatusOK,"listthings.html",gin.H{"res":browser.Prizes})
		}
	}
}
func (ach *AchievementController)GetNewThings(ctx *gin.Context){
	if browser.AuthLevel==2{
		ctx.JSON(http.StatusOK,gin.H{
			"error":"管理人员无权操作！",
		})
	}else if browser.AuthLevel==1{
		ctx.HTML(http.StatusOK,"addthings.html",nil)
	}
}
func (ach *AchievementController)PostAddThing(ctx *gin.Context){
	browser.AddPerize(ctx)
	ctx.HTML(http.StatusOK,"addthings.html",nil)
}
//专利
func (ach *AchievementController)GetPatent(ctx *gin.Context){
	patentID:=ctx.Query("PatentID")
	if patentID==""{
		browser.GetPatentsInfo(ctx)
		ctx.HTML(http.StatusOK,"listpatent.html",gin.H{"res":browser.Patents})
	}else{
		if browser.AuthLevel==1{
			ctx.JSON(http.StatusOK,gin.H{
				"error":"普通用户无权操作！",
			})
		}else if browser.AuthLevel==2{
			_patentID,_:=strconv.ParseInt(patentID,10,64)
			browser.CheckPatent(ctx,&_patentID)
			browser.GetPatentsInfo(ctx)
			ctx.HTML(http.StatusOK,"listpatent.html",gin.H{"res":browser.Patents})
		}
	}
}
func (ach *AchievementController)PostPatent(ctx *gin.Context){
	if browser.AuthLevel==1{
		ctx.JSON(http.StatusOK,gin.H{
			"error":"普通用户无权操作！",
		})
	}else if browser.AuthLevel==2{
		patentId:=ctx.PostForm("PatentID")
		if patentId==""{
			ctx.HTML(http.StatusOK,"listpatent.html",gin.H{"res":browser.Patents})
		}else{
			_patentId,_:=strconv.ParseInt(patentId,10,64)
			browser.DetetePatent(ctx,&_patentId)
			ctx.HTML(http.StatusOK,"listpatent.html",gin.H{"res":browser.Patents})
		}
	}
}
func (ach *AchievementController)GetAddPatent(ctx *gin.Context){
	if browser.AuthLevel==2{
		ctx.JSON(http.StatusOK,gin.H{
			"error":"管理人员无权操作！",
		})
	}else if browser.AuthLevel==1{
		ctx.HTML(http.StatusOK,"addpatent.html",nil)
	}
}
func (ach *AchievementController)PostAddPatent(ctx *gin.Context){
	browser.AddPatent(ctx)
	ctx.HTML(http.StatusOK,"addpatent.html",nil)
}