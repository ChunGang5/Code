package main

import (
	"fmt"
	//"go/ast"

	//"math"
)

/*
import "encoding/json"

type Student struct {
	name string
	age int
	sex string
}

func (s1 Student)test(){
	fmt.Printf("name is %s\n",s1.name)
	fmt.Println(s1.name,"是一个好人！")
}
func main(){
	
	fmt.Println("test")
	var num int=10
	if num<15 {
		fmt.Println("too letter")
	}

	var years int
	fmt.Scanf("%d",&years)
	if (years%4==0 && years%100!=0)||years%400==0{
		fmt.Println("闰年")
	}


	var a,b,c float64
	fmt.Scanf("%f,%f,%f",a,b,c)

	m:=b*b-4*a*c

	if m>0{
		x1:=(-b+math.Sqrt(m))/2*a
		x2:=(-b-math.Sqrt(m))/2*a
		fmt.Printf("x1=%v,x2=%v\n",x1,x2)
	}else if m == 0{
		x:=(-b+math.Sqrt(m))/2*a
		fmt.Printf("x=%v\n",x)
	}else{
		fmt.Println("NO")
	}


	var Map map[string]string
	Map=make(map[string]string,3)
	Map["chen"]="陈"
	Map["chun"]="春"

	fmt.Println(Map)
	Map1:=make(map[string]int,10)
	Map1["sa"]=1
	Map1["sad"]=2

	fmt.Println(Map1)

	Map2:=map[int]int{
		1:10,
		2:20,
	}
	delete(Map2,2)
	fmt.Println(Map2)

	val,ok:=Map["chen"]
	if ok{
		fmt.Printf("exsit chen,value is %v",val)
	}else{
		fmt.Println("No chen")
	}



	var student1 Student
	student1.name="陈刚"
	student1.age=23
	student1.sex="男"

	fmt.Println(student1)
	student2:=Student{"春",21,"nv"}
	fmt.Println(student2)

	var P_student *Student=new(Student)
	P_student.name="sai"
	P_student.age=20
	P_student.sex="女"
	fmt.Println(*P_student)

	student1.test()


	type Monster struct {
		Name string `json:"name"`
		Age int	`json:"age"`
		Skill string `json:"skill"`
	}

	monstr:=Monster{"蚕豆",10,"风采看"}

	jsonStr,err:=json.Marshal(monstr)
	if err!=nil{
		fmt.Println("error!")
	}else{
		fmt.Println("jsonstr:",string(jsonStr))
	}

	var s Student
	s.name="陈刚"
	s.sex="男"
	s.age=23
	s3:=Student{"拆开",23,"女"}
	s.test()
	s3.test()
}


type Student struct{
	name string
	age int
}

func (s Student)String() string{
	str:=fmt.Sprintf("name is %s, age is %d\n",s.name,s.age)
	return str
}

func main(){
	s :=Student{"陈刚",23}
	str:=s.String()
	fmt.Println(str)
}



type MethodUtils struct{

}
func (mu MethodUtils) Print(m int,n int){
	for i:=0;i<m;i++{
		for j:=0;j<n;j++{
			fmt.Print("*")
		}
		fmt.Println()
	}
}

func main(){
	var me MethodUtils
	me.Print(5,10)
}

 */

