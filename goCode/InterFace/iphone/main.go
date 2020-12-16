package main

import "fmt"

/*
type Usb interface {
	Start()
	Stop()
}
type Iphone struct {
}

func (p Iphone) Start() {
	fmt.Println("苹果手机启动")
}
func (p Iphone) Stop() {
	fmt.Println("苹果手机关机")
}

type Android struct {
}

func (a Android) Start() {
	fmt.Println("安卓收手机启动")
}
func (a Android) Stop() {
	fmt.Println("安卓手机关机")
}

type machine struct {
}

func (m machine) Working(u Usb) {
	u.Start()
	u.Stop()
}
func main() {
	iphone11 := Iphone{}
	mi := Android{}
	m := machine{}

	m.Working(iphone11)
	m.Working(mi)
}


type Test interface {
	Say()
	//Try()
}
type Stu struct {
	Name string
}

func (s Stu) Say() {
	fmt.Println(s.Name)
}

type test int

func (I test) Say() {
	fmt.Println("ok")
}
func main() {
	var s Stu = Stu{
		Name: "chengang",
	}
	var a Test = s
	a.Say()
	var i test
	var b Test = i
	b.Say()
}
*/

type TestFace1 interface {
	Say()
	//name string
}

type TestFace2 interface {
	TestFace1
	Hello()
}

type monster struct {
	Name string
	age  int
}

func (m monster) Say() {
	fmt.Printf("%s,Say ok\n", m.Name)
}
func (m monster) Hello() {
	fmt.Println("Hello ok,m.age")
}

func main() {
	var m monster = monster{
		Name: "黑金偶爱哦对",
		age:  23,
	}
	var t1 TestFace1 = m
	t1.Say()
	var t2 TestFace2 = m
	t2.Hello()
}
