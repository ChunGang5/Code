package model

import "fmt"

type person struct {
	Name string
	age  int
	sal  float64
}

//工厂模式来构建，相当于构建了一个对象，具有实际的内存的对象，相当于构造函数
func NewPerson(name string) *person {
	return &person{
		Name: name,
	}
}

func (p *person) SetAge(age int) {
	if age > 0 && age < 100 {
		p.age = age
	} else {
		fmt.Println("age input error!")
	}
}

func (p *person) SetSal(sal float64) {
	p.sal = sal
}

func (p *person) Getage() int {
	return p.age
}

func (p *person) GetSal() float64 {
	return p.sal
}
