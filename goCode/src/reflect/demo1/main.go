package main

import (
	"fmt"
	"reflect"
)

/*
func reflectTest01(b interface{}) {
	rType := reflect.TypeOf(b)
	fmt.Println("Type = :", rType)
	rValue := reflect.ValueOf(b)
	fmt.Println("Value = :", rValue)
}
func main() {
	var num int
	reflectTest01(num)
}


type Student struct {
	Name string
	Age  int
}

func reflectTest02(s interface{}) {
	rType := reflect.TypeOf(s)
	rValue := reflect.ValueOf(s)
	fmt.Printf("Type = %v,Value =%v \n", rType, rValue)

	iV := rValue.Interface()
	fmt.Printf("iv = %v ,iv type = %T\n", iV, iV)

	stu, ok := iV.(Student)
	if ok {
		fmt.Printf("stu.Name=%v\n", stu.Name)
	}
}
func main() {
	stu := Student{
		Name: "Tom",
		Age:  5,
	}
	reflectTest02(stu)
}
*/

func reflectTest03(s interface{}) {
	rType := reflect.TypeOf(s)
	rValue := reflect.ValueOf(s)
	fmt.Printf("Type = %v,Value = %v\n", rType, rValue)
	rKind := rValue.Kind()
	fmt.Println(rKind)
	iv := rValue.Interface()
	s, ok := iv.(float64)
	if ok {
		fmt.Println(s)
	}

}
func main() {
	var num float64 = 1.2
	reflectTest03(num)
}
