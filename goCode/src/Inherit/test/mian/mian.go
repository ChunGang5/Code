package main

import "fmt"

type A struct {
	Name string
	age  int
}

func (a *A) SayOk() {
	fmt.Println("saying ok!")
}

type B struct {
	A
	Sex string
}

func (b B) HelloB() {
	fmt.Println("this is B model")
}

func main() {
	var a A = A{
		"tom",
		23,
	}
	fmt.Println(a)
	a.SayOk()

	var b B
	b.A.Name = "jon"
	b.A.age = 55
	b.Sex = "男"
	fmt.Println(b)
	b.SayOk()
	b.HelloB()
}
