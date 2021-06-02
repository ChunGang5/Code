package browser

import (
	"github.com/gin-gonic/gin"
	"goLaCode/server"
	"net/http"
	"fmt"
	"strconv"
)

var Patents []server.Patent

func GetPatentsInfo(ctx *gin.Context){
	if AuthLevel==1{
		if err:=server.DB.Debug().Where("patent_owner_id=?",User.ID).Find(&Patents).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("用户拥有专利查询成功")
	}else if AuthLevel==2{
		if err:=server.DB.Find(&Patents).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("管理员查询所有专利成功")
	}
}

func AddPatent(ctx *gin.Context){
	PatentID,_:=strconv.ParseInt(ctx.PostForm("PatentID"),10,64)
	PatentOwnerID:=User.ID
	PatentName:=ctx.PostForm("PatentName")
	PatentOwner:=User.Name
	PatentType:=ctx.PostForm("PatentType")
	ApplyDate:=ctx.PostForm("ApplyDate")
	GrantDate:=ctx.PostForm("GrantDate")
	Fee:=ctx.PostForm("Fee")

	newPatent:=server.Patent{
		PatentID:      PatentID,
		PatentName:    PatentName,
		PatentOwner:   PatentOwner,
		User:          server.User{},
		PatentOwnerID: PatentOwnerID,
		PatentType:    PatentType,
		ApplyDate:     ApplyDate,
		GrantDate:     GrantDate,
		Fee:           Fee,
		AuditStatus:	"未审核",
	}
	server.DB.Create(&newPatent)
}

func DetetePatent(ctx *gin.Context,patentId *int64){
	var patent server.Patent
	if err:=server.DB.Debug().Where("patent_id=?",*patentId).First(&patent).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}
	server.DB.Debug().Delete(&patent)

	if err:=server.DB.Find(&Patents).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}
}
func CheckPatent(ctx *gin.Context,patentID *int64){
	var patent server.Patent
	if err:=server.DB.Debug().Where("patent_id=?",*patentID).First(&patent).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}
	server.DB.Debug().Model(&patent).Update("audit_status","已审核")
}