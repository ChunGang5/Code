package main

import (
	"fmt"
	"time"
)

func test() {
	for i := 0; i < 10; i++ {
		fmt.Println("test(),hello test")
		time.Sleep(time.Second)
	}
}

//不稳定
func main() {
	go test()
	for i := 0; i < 10; i++ {
		fmt.Println("main(),hello golang")
		time.Sleep(time.Second)
	}
}
