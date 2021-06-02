package browser

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/server"
	"net/http"
	"strconv"
)

func ApplyProject(ctx *gin.Context){
	fmt.Println("获取用户申请立项成功")
	if AuthLevel==1{	//普通用户
		if err:=server.DB.Debug().Where("proposer_id=? AND project_status=?",User.ID,"立项审核").Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("用户拥有的处于理想审核项目查询成功")
	}else if AuthLevel==2{	//管理人员
		if err:=server.DB.Debug().Where("project_status=?","立项审核").Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("管理员查询所有用户待审核项目成功")
	}
}

func ApplyThroughProject(ctx *gin.Context,pid *int64){
	fmt.Printf("获取到要操作的PID为%d\n",*pid)
	/*fmt.Println("获取用户申请立项已通过成功")
	if AuthLevel==1{	//普通用户
		if err:=server.DB.Debug().Where("proposer_id=? AND project_status=?",User.ID,"立项审核").Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("用户拥有的处于立项审核通过项目查询成功")
	}else if AuthLevel==2{	//管理人员*/
		var project server.Project
		if err:=server.DB.Debug().Where("p_id=?",*pid).First(&project).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		server.DB.Debug().Model(&project).Update("ProjectStatus","立项成功")
		//立项日期
		approvalDate:="2021-05-15"
		server.DB.Debug().Model(&project).Update("ApprovalDate",approvalDate)
		//审核后
		if err:=server.DB.Debug().Where("project_status=?","立项审核").Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("管理员查询所有用户待立项审核项目成功")
	/*}*/
}

func RejectApplyProject(ctx *gin.Context,pid *int64){
	/*fmt.Printf("获取到要操作的PID为%d\n",*pid)
	if AuthLevel==1{	//普通用户
		if err:=server.DB.Debug().Where("proposer_id=? AND project_status=?",User.ID,"立项审核").Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("用户拥有的处于立项审核通过项目查询成功")
	}else if AuthLevel==2{	//管理人员*/
		var project server.Project
		if err:=server.DB.Debug().Where("p_id=?",*pid).First(&project).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		server.DB.Debug().Model(&project).Update("ProjectStatus","立项未通过")
		//审核后
		if err:=server.DB.Debug().Where("project_status=?","立项审核").Find(&Projects).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("管理员查询所有用户待立项审核项目成功")
	/*}*/
}

func AddNewApplyProject(ctx *gin.Context){
	fmt.Println("申请新项目调用成功")
	PID,_:=strconv.ParseInt(ctx.PostForm("PID"),10,64)
	PName:=ctx.PostForm("PName")
	Proposer:=ctx.PostForm("Proposer")
	College:=ctx.PostForm("College")
	ProType:=ctx.PostForm("ProType")
	ApplicationDate:=ctx.PostForm("ApplicationDate")
	ProBudget,_:=strconv.ParseInt(ctx.PostForm("ProBudget"),10,64)
	newp:=server.Project{
		PID:             PID,
		PName:           PName,
		Proposer:        Proposer,
		User:            server.User{},
		ProposerID:      User.ID,
		College:         College,
		ProType:         ProType,
		ApplicationDate: ApplicationDate,
		ApprovalDate:    "",
		ProBudget:       ProBudget,
		ProjectStatus:   "立项审核",
	}
	server.DB.Create(&newp)
}