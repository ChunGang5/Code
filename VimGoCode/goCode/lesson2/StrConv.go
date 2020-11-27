package main

import (
	"fmt"
	"strconv"
)

func main() {
	num1 := 99
	num2 := 23.456
	flag := true

	str1 := strconv.FormatInt(int64(num1), 10)
	fmt.Printf("var is %T : %v\n", str1, str1)

	str2 := strconv.FormatFloat(float64(num2), 'f', 10, 64)
	fmt.Printf("%T : %v\n", str2, str2)

	str3 := strconv.FormatBool(flag)
	fmt.Printf("%T : %v\n", str3, str3)

	num3 := 1546
	str4 := strconv.Itoa(num3)
	fmt.Printf("%T : %v\n", str4, str4)
}
