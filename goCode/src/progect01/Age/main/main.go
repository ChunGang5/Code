package main

import (
	"fmt"
	"progect01/Age/model"
)

func main() {
	var ps = model.NewPerson("tom")
	ps.SetAge(23)
	ps.SetSal(50000)
	fmt.Println(*ps)
}
