package browser

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/server"
	"net/http"
	"strconv"
)
var Periodicals []server.Periodical
func GetPeriodicalInfo(ctx *gin.Context){
	fmt.Println("获取用户论文信息")
	if AuthLevel==1{
		if err:=server.DB.Debug().Where("author_id=?",User.ID).Find(&Periodicals).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("用户拥有论文查询成功")
	}else if AuthLevel==2{
		if err:=server.DB.Debug().Find(&Periodicals).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("管理员查询所有项目成功")
	}
}
func AddPeriodical(ctx *gin.Context){
	fmt.Println("添加新论文成果")
	AccessionNum,_:=strconv.ParseInt(ctx.PostForm("AccessionNum"),10,64)
	AuthorID:=User.ID
	Title:=ctx.PostForm("Title")
	PeriodicalType:=ctx.PostForm("PeriodicalType")
	Subject:=ctx.PostForm("Subject")
	Collecyion:=ctx.PostForm("Collecyion")
	Date:=ctx.PostForm("Date")
	Author:=User.Name
	newPeriodical:=server.Periodical{
		AccessionNum:   AccessionNum,
		Title:          Title,
		Author:         Author,
		User:           server.User{},
		AuthorID:       AuthorID,
		PeriodicalType: PeriodicalType,
		Subject:        Subject,
		Collecyion:     Collecyion,
		Date:           Date,
		AuditStatus:    "待审核",
	}
	server.DB.Create(&newPeriodical)
}

func DeletePeriocals(ctx *gin.Context,accessionNum *int64){
	var periocal server.Periodical
	if err:=server.DB.Debug().Where("accession_num=?",*accessionNum).First(&periocal).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}
	//periocal.AccessionNum=*accessionNum
	server.DB.Debug().Delete(&periocal)
	//删除后
	if err:=server.DB.Find(&Periodicals).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}
}

func CheckPeriocals(ctx *gin.Context,accessionNum *int64){
	var periodical server.Periodical
	if err:=server.DB.Debug().Where("accession_num=?",*accessionNum).First(&periodical).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}
	server.DB.Debug().Model(&periodical).Update("audit_status","已审核")
}
