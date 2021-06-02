package browser

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/server"
	"net/http"
	"strconv"
)

var Prizes []server.Prize

func GetPerizeInfo(ctx *gin.Context){
	fmt.Println("获取用户获奖信息")
	if AuthLevel==1{
		if err:=server.DB.Debug().Where("prize_user_id=?",User.ID).Find(&Prizes).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("用户拥有奖项查询成功")
	}else if AuthLevel==2{
		if err:=server.DB.Find(&Prizes).Error;err!=nil{
			ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		}
		fmt.Println("管理员查询所有奖项成功")
	}
}

func AddPerize(ctx *gin.Context){
	fmt.Println("添加新奖项")
	PrizeID,_:=strconv.ParseInt(ctx.PostForm("PrizeID"),10,64)
	PrizeUserID:=User.ID
	PrizeName:=ctx.PostForm("PrizeName")
	Awaridee:=User.Name
	PrizeType:=ctx.PostForm("PrizeType")
	PrizeDate:=ctx.PostForm("PrizeDate")
	newPrize:=server.Prize{
		PrizeID:     PrizeID,
		PrizeName:   PrizeName,
		User:        server.User{},
		PrizeUserID: PrizeUserID,
		Awaridee:    Awaridee,
		PrizeType:   PrizeType,
		PrizeDate:   PrizeDate,
		AuditStatus: "未审核",
	}
	server.DB.Create(&newPrize)
}

func DeletePrize(ctx *gin.Context,prizeID *int64){
	var prize server.Prize
	fmt.Printf("获取要移出的奖项ID:%d\n",*prizeID)
	if err:=server.DB.Debug().Where("prize_id=?",*prizeID).First(&prize).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}
	server.DB.Debug().Delete(&prize)
	//删除后
	if err:=server.DB.Find(&Prizes).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}
}

func CheckPrize(ctx *gin.Context,prizeID *int64){
	var perize server.Prize
	if err:=server.DB.Debug().Where("prize_id=?",*prizeID).First(&perize).Error;err!=nil{
		ctx.JSON(http.StatusOK,gin.H{"error":(err).Error()})
	}
	server.DB.Debug().Model(&perize).Update("audit_status","已审核")
}
