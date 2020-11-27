package main

import "fmt"
import "homeWork"

func main() {
	var name string
	var age int
	var sex string
	var iphone int

	fmt.Println("输入姓名")

	fmt.Scanln(&name)

	fmt.Println("输入年龄")
	fmt.Scanf("%d\n", &age)

	fmt.Scanln(&sex)
	fmt.Scanf("%d\n", &iphone)

	fmt.Printf("%s, %d, %s, %d\n", name, age, sex, iphone)

	fmt.Printf("add is %d\n", homeWork.Add(age, iphone))
}
