package main

import (
	"fmt"
	"progect01/factory/model"
)

func main() {
	var stu = model.NewStudent("tim", 88.9)
	//fmt.Println(*stu)
	fmt.Println("Name:", (*stu).Name)
	fmt.Println("Score:", stu.GetScore())
}
