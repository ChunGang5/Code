package browser

import (
	"errors"
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/server"
	"net/http"
	"strconv"
)
var (
	Err *error
)
var User *server.User=&server.User{}

func Login(c *gin.Context)(err error){
	fmt.Println("Login调用成功")
	userId,_:=strconv.ParseInt(c.PostForm("Id"),10,64)
	passWord:=c.PostForm("password")
	fmt.Printf("Id=%d,password=%s\n",userId,passWord)
	tempUser:=server.User{
		ID:                   0,
		Password:             "",
		Name:                 "",
		Position:             "",
		GraduateInstitutions: "",
		Sex:                  "",
		Hiredate:             "",
		Degree:               "",
		BirthTime:            "",
		Department:           "",
		Telephone:            "",
		Email:                "",
		PoliticStatus:        "",
		EducationBackground:  "",
		Address:              "",
		Authority:            server.Authority{},
		AuthID:               0,
	}
	*User=tempUser
	if err=server.DB.Debug().Where("id=?",userId).First(User).Error; err!=nil{
		c.JSON(http.StatusOK,gin.H{"error":(err).Error()})
		return
	}
	//fmt.Println("select succeed")
	//fmt.Println("User的密码："+User.Password)
	if User.Password==passWord{
		fmt.Println("登录成功")
		//c.JSON(http.StatusOK,gin.H{"登录成功":userName})
	}else{
		fmt.Println("密码错误")
		c.JSON(http.StatusOK,gin.H{"密码错误":passWord})
		err=errors.New("密码错误")
		return err
	}
	return
}
