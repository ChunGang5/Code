package main

import "fmt"

// type Point struct {
// 	x int
// 	y int
// }

// func main() {
// 	var a interface{}
// 	var point Point = Point{1, 2}
// 	a = point
// 	var b Point
// 	b = a.(Point)
// 	fmt.Println(b)
// }

func main() {
	var x interface{}
	var b float32 = 1.1
	x = b
	if y, ok := x.(float32); ok {
		fmt.Println("Success")
		fmt.Printf("%T : %v\n", y, y)
	} else {
		fmt.Println("covert fail")
	}
	fmt.Println("继续")
}
