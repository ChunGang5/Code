package main

import (
	"fmt"
)

func main() {
	var x complex128 = complex(1, 2)
	fmt.Printf("real is %v,imag is %v", real(x), imag(x))
}
