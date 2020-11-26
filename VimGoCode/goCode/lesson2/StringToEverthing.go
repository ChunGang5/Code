package main

import "fmt"

func main() {
	var num1 int = 99
	//var num2 float64 = 23.456
	//var flag bool = true

	//var bit byte = 'h'
	var str string

	str = fmt.Sprintf("%d", num1)
	fmt.Printf("str type %T str=%q\n", str, str)
}
