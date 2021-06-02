package browser

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/server"
	"net/http"
)
var Projects []server.Project
var AuthLevel int64
func GetAthuLevel(ctx *gin.Context){
	authority:=server.Authority{}
	if err:=server.DB.Where("ID=?",User.ID).First(&authority).Error; err != nil {
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		return
	}
	fmt.Printf("该用户的权限级别为：%d级\n",authority.AuthLevel)
	AuthLevel=authority.AuthLevel
}
func GetUserProjectInfos(ctx *gin.Context){
	fmt.Println("获取用户项目信息")
	/*authority:=server.Authority{}
	if err:=server.DB.Where("ID=?",User.ID).First(&authority).Error; err != nil {
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		return
	}
	fmt.Printf("该用户的权限级别为：%d级\n",authority.AuthLevel)*/

	if AuthLevel==1{
		//显示用户拥有的项目
		if err:=server.DB.Debug().Where("proposer_id=?",User.ID).Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("用户拥有项目查询成功")
		//fmt.Println(Projects[0].PName)
	}else if AuthLevel==2{
		//显示所有用户拥有的项目信息
		if err:=server.DB.Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("管理员查询所有项目成功")
		//fmt.Println(Projects[1].PName)
	}
}

//中期阶段
func GetMidProject(ctx *gin.Context){
	fmt.Println("正在查询中期阶段.....")
	if AuthLevel==1{
		if err:=server.DB.Debug().Where("proposer_id=? AND project_status LIKE ?",User.ID,"%中期%").Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
	}else if AuthLevel==2 {
		if err := server.DB.Debug().Where("project_status LIKE ?", "%中期%").Find(&Projects).Error; err != nil {
			ctx.JSON(http.StatusOK, gin.H{"error": (err).Error()})
		}
	}
}
func GetFinishStagr(ctx *gin.Context){
	if AuthLevel==1{
		if err:=server.DB.Debug().Where("proposer_id=? AND project_status LIKE ?",User.ID,"%结题%").Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
	}else if AuthLevel==2 {
		if err := server.DB.Debug().Where("project_status LIKE ?", "%结题%").Find(&Projects).Error; err != nil {
			ctx.JSON(http.StatusOK, gin.H{"error": (err).Error()})
		}
	}
}

func GetNoPassProject(ctx *gin.Context){
	if AuthLevel==1{
		if err:=server.DB.Debug().Where("proposer_id=? AND project_status LIKE ?",User.ID,"%未通过%").Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
	}else if AuthLevel==2 {
		if err := server.DB.Debug().Where("project_status LIKE ?", "%未通过%").Find(&Projects).Error; err != nil {
			ctx.JSON(http.StatusOK, gin.H{"error": (err).Error()})
		}
	}
}