package server

import (
	//"fmt"
	"github.com/jinzhu/gorm"
	_ "github.com/jinzhu/gorm/dialects/mysql"
)
var(
	DB *gorm.DB
)

//角色
type Authority struct {
	ID int64	`gorm:"PRIMARY_KEY;unique;not null;AUTO_INCREMENT"`
	AuthLevel int64		//权限级别
	AuthCo string		//权限内容
}
//用户信息
type User struct {
	ID int64	`grom:"PRIMARY_KEY;unique;not null;AUTO_INCREMENT" json:"Id" from:Id`	//工号
	Password string `json:password from:password`
	Name string `grom:"type:varchar(15);" json:"Name" from:Name`
	Position string `json:"Position" from:Position`		//职位
	GraduateInstitutions string	`json:"Graduate_institutions" from:Graduate_institutions`	//毕业院校
	//Age int64
	Sex string	`json:"Sex" from:Sex`
	Hiredate string	`json:"Hiredate" from:Hiredate`	//入职时间
	//学士，硕士，博士，其他
	Degree string	`json:"Degree" from:Degree`		//学位
	BirthTime string `json:"Birth_time" from:Birth_time`	//出生日期
	Department string `json:"Department" from:Department`	//部门
	Telephone string `json:"Telephone" from:Telephone`
	Email string `json:"Email" from:Email`
	PoliticStatus string `json:"Politic_status" from:Politic_status`	//政治面貌
	//本科,硕士研究生,博士研究生,其他
	EducationBackground string 	`json:"Education_background" from:Education_background`	//学历
	Address string `json:"Address" from:Address`
	Authority Authority `gorm:"FOREIGNKEY:AuthID;ASSOCIATION_FOREIGNKEY:ID"`
	AuthID int64
}
//科研项目
type Project struct{
	PID int64	`gorm:"PRIMARY_KEY;unique;not null;AUTO_INCREMENT" json:"PID" from:"PID"`
	PName string	`json:"PName" from:"PName"`
	Proposer string	`json:"Proposer from:"Proposer"`		//申请人
	User User	`gorm:"FOREIGNKEY:ProposerID;ASSOCIATION_FOREIGNKEY:ID`
	ProposerID	int64				//申请人ID
	College string	`json:"College" from:"College"`			//所属学院
	ProType string	`json:"ProType" from:"ProType"`		//项目类型
	ApplicationDate string	`json:"ApplicationDate" from:"ApplicationDate"`	//申请日期
	ApprovalDate string	`json:"ApprovalDate"` //立项日期
	ConcludingDate string	`json:"ConcludingDate"` //结题日期
	ProBudget int64	`json:"ProBudget" from:"ProBudget"` //项目预算
	ProjectStatus string `json:"ProjectStatus" from:"ProjectStatus"`	 	//项目状态
}
//论文期刊
type Periodical struct {
	AccessionNum int64	`gorm:"PRIMARY_KEY;unique;not null;AUTO_INCREMENT" json:"AccessionNum"`//检索号
	Title string `json:"Title"`	//论文名称
	Author string	`json:"Author"`	//作者
	User User `gorm:"FOREIGNKEY:AuthorID;ASSOCIATION_FOREIGNKEY:ID"`
	AuthorID int64 `json:"AuthorID"`	//作者ID
	PeriodicalType string `json:"PeriodicalType"`	//论文类别
	Subject	string `json:"Subject"`		//学科类别
	Collecyion string	`json:"Collecyion"`	//收录情况
	Date string `json:"Date"`			//收录时间
	AuditStatus string 	`json:"AuditStatus"`//审核状态
}
//获奖表
type Prize struct {
	PrizeID int64 `gorm:"PRIMARY_KEY;unique;not null;AUTO_INCREMENT"	json:"PrizeID"`	//获奖批准号
	PrizeName string	`json:"PrizeName"`
	User User `gorm:"FOREIGNKEY:PrizeUserID;ASSOCIATION_FOREIGNKEY:ID" "`
	PrizeUserID int64 `json:"PrizeUserID"`	//获奖人ID
	Awaridee string	`json:"Awaridee"` 	//获奖人名称
	PrizeType string	`json:"PrizeType"`	//获奖类型
	PrizeDate string	`json:"PrizeDate"`//获奖时间
	AuditStatus string 	`json:"AuditStatus"`//审核状态
}
//专利表
type Patent struct {
	PatentID int64	`gorm:"PRIMARY_KEY;unique;not null;AUTO_INCREMENT" json:"PatentID"`
	PatentName string	`json:"PatentName"`
	PatentOwner string	`json:"PatentOwner"`//专利用有人
	User User `gorm:"FOREIGNKEY:PatentOwnerID;ASSOCIATION_FOREIGNKEY:ID"`
	PatentOwnerID int64	//专利用有人ID
	PatentType string	`json:"PatentType"`	//专利类别
	ApplyDate string       `json:"ApplyDate"`	//申请日期
	GrantDate string `json:"GrantDate"`	//授权日期
	Fee string 	`json:"Fee"`		//是否在续
	AuditStatus string 	`json:"AuditStatus"`//审核状态
}
//留言表
type Message struct {
	MID int64 `gorm:"PRIMARY_KEY;unique;not null;AUTO_INCREMENT" json:"MID"`
	MUserName string `json:"MUserName"`
	DateTime string	`json:"DateTime"`
	Content string 	`json:"Content"`
}
func InitMysql()(err error) {
	DB, err = gorm.Open("mysql", "root:@tcp(127.0.0.1:3306)/db1?charset=utf8mb4&loc=Local&parseTime=true")
	if err!=nil{
		return
	}
	return DB.DB().Ping()
}

func DataBases() {
	err:=InitMysql()
	if err!=nil{
		panic(err)
	}
	//后台创建表
	DB.AutoMigrate(&User{})
	u1:=User{
		1,
		"yyccgg.55",
		"陈刚",
		"学生",
		"西安财经大学",
		"男",
		"2017-09-08",
		"学士",
		"1997-02-29",
		"信息学院",
		"13772603124",
		"1330431376@qq.com",
		"共青团员",
		"本科",
		"陕西省咸阳市",
		Authority{},
		1,
	}
	if DB.NewRecord(&u1){//判断主键是否为空 true
		DB.Create(&u1)
	}

	//建Authority表
	DB.AutoMigrate(&Authority{})
	a1:=Authority{
		ID:        1,
		AuthLevel: 1,
		AuthCo:    "科研",
	}
	if DB.NewRecord(&a1){//判断主键是否为空 true
		DB.Create(&a1)
	}
	
	//建立Project表
	DB.AutoMigrate(&Project{})
	p1:=Project{
		PID:           1,
		PName:         "科研管理系统",
		Proposer:      "陈刚",
		User:          User{},
		ProposerID:    1,
		College:       "应用研究类",
		ProType:       "计算机科学",
		ApplicationDate:"2021-04-15",
		ApprovalDate:  "2021-05-05",
		ConcludingDate:"2025-05-15",
		ProBudget:     10000,
		ProjectStatus: "立项审核",
	}
	if DB.NewRecord(&p1){//判断主键是否为空 true
		DB.Create(&p1)
	}
	//建立Periodical表	论文期刊
	DB.AutoMigrate(&Periodical{})
	Per1:=Periodical{
		AccessionNum:   1,
		Title:          "量子力学",
		Author:         "陈刚",
		User:           User{},
		AuthorID:       1,
		PeriodicalType: "理论性论文",
		Subject:        "物理学",
		Collecyion:     "知网收录",
		Date:           "2019-07-11",
		AuditStatus:    "审核通过",
	}
	if DB.NewRecord(&Per1){//判断主键是否为空 true
		DB.Create(&Per1)
	}

	//建立Prize表	获奖
	DB.AutoMigrate(&Prize{})
	pri1:=Prize{
		PrizeID:     1,
		PrizeName:   "优秀论文奖",
		User:        User{},
		PrizeUserID: 1,
		Awaridee:    "陈刚",
		PrizeType:   "自然科学奖",
		PrizeDate:   "20200315",
		AuditStatus: "审核通过",
	}
	if DB.NewRecord(&pri1){//判断主键是否为空 true
		DB.Create(&pri1)
	}
	//建立专利表
	DB.AutoMigrate(&Patent{})
	pat1:=Patent{
		PatentID:      1,
		PatentName:    "曲率引擎技术",
		PatentOwner:   "张三",
		User:          User{},
		PatentOwnerID: 2,
		PatentType:    "应用科学",
		ApplyDate:     "20350518",
		GrantDate:     "20900716",
		Fee:           "是",
		AuditStatus:   "审核通过",
	}
	if DB.NewRecord(&pat1){//判断主键是否为空 true
		DB.Create(&pat1)
	}
	//建立Message
	DB.AutoMigrate(&Message{})
	mes:=Message{
		MID:       1,
		MUserName: "陈刚",
		DateTime:  "2021-05-17 00:41:18",
		Content:   "科研管理系统终于设计完成",
	}
	if DB.NewRecord(&mes){
		DB.Create(&mes)
	}
}

func LoginFind(Id int, Password string)bool{
	var user User
	DB.Where("ID=?",Id).Find(&user)
	return true
}
