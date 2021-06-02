package browser

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"goLaCode/server"
)

func ChangeUserInfo(ctx *gin.Context){
	fmt.Println("调用ChangeUserInfo()成功 ")
	//passWord:=User.Password
	Name:=ctx.PostForm("Name")
	Position:=ctx.PostForm("Position")
	Graduate_institutions:=ctx.PostForm("Graduate_institutions")
	Sex:=ctx.PostForm("Sex")
	//fmt.Println("开始打印修改后的信息")
	//fmt.Println(Sex)
	Hiredate:=ctx.PostForm("Hiredate")
	Degree:=ctx.PostForm("Degree")
	Birth_time:=ctx.PostForm("Birth_time")
	Department:=ctx.PostForm("Department")
	Telephone:=ctx.PostForm("Telephone")
	Email:=ctx.PostForm("Email")
	Politic_status:=ctx.PostForm("Politic_status")
	Education_background:=ctx.PostForm("Education_background")
	Address:=ctx.PostForm("Address")
	server.DB.Model(User).Updates(server.User{
		//ID:Id,
		Name:Name,
		Position:Position,
		GraduateInstitutions:Graduate_institutions,
		Sex:Sex,
		Hiredate:Hiredate,
		Degree:Degree,
		BirthTime:Birth_time,
		Department:Department,
		Telephone:Telephone,
		Email:Email,
		PoliticStatus:Politic_status,
		EducationBackground:Education_background,
		Address:Address,
	})
	fmt.Println("修改用户信息成功")
	/*
	Id,_:=strconv.ParseInt(ctx.PostForm("Name"),10,64)
	User.ID=Id
	password:=User.Password
	User.Password=password
	User.Name=ctx.PostForm("Name")
	User.Position=ctx.PostForm("Position")
	User.GraduateInstitutions=ctx.PostForm("Graduate_institutions")
	User.Sex=ctx.PostForm("Sex")
	User.Hiredate=ctx.PostForm("Hiredate")
	User.Degree=ctx.PostForm("Degree")
	User.BirthTime=ctx.PostForm("Birth_time")
	User.Department=ctx.PostForm("Department")
	User.Telephone=ctx.PostForm("Telephone")
	User.Email=ctx.PostForm("Email")
	User.PoliticStatus=ctx.PostForm("Politic_status")
	User.EducationBackground=ctx.PostForm("Education_background")
	User.Address=ctx.PostForm("Address")
	 */

}
