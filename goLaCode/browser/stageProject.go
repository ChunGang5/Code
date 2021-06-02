package browser

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/server"
	"net/http"

)

func GetStageProject(ctx *gin.Context){
	fmt.Println("获取用户处于立项成功的项目成功")
	if AuthLevel==1{	//普通用户
		if err:=server.DB.Debug().Where("proposer_id=? AND project_status=?",User.ID,"立项成功").Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("用户拥有的处于立项成功阶段项目查询成功")
	}else if AuthLevel==2{	//管理人员
		if err:=server.DB.Debug().Where("project_status=?","立项成功").Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("管理员查询所有用户立项成功项目成功")
	}
}

func ChangeProjectStatus(ctx *gin.Context,pid *int64,projectStatus *string,concludingDate *string){
	fmt.Println("改变项目状态调用成功")
	fmt.Printf("要修改的PID=%d,ProjectStatus=%s\n",*pid,*projectStatus)
	var updateProject server.Project
	if err:=server.DB.Debug().Where("p_id=?",*pid).First(&updateProject).Error;err!= nil {
		ctx.JSON(http.StatusOK,gin.H{"error":err.Error()})
	}
	fmt.Printf("找到要更改的项目是%s\n",updateProject.PName)
	//修改状态
	if *concludingDate==""{
		server.DB.Debug().Model(&updateProject).Update("ProjectStatus",*projectStatus)
	}else{
		server.DB.Debug().Model(&updateProject).Updates(server.Project{ProjectStatus:*projectStatus,ConcludingDate:*concludingDate})
	}

	/*if err:=server.DB.Debug().Where("project_status=?","立项成功").Find(&Projects).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}*/
	fmt.Println("修改项目状态成功")
}
