package main

import (
	"fmt"
	"runtime"
)

/*
func main() {
	messages := make(chan string)
	go func() {
		messages <- "ping"
	}()
	msg := <-messages
	fmt.Println(msg)
}
*/

func main() {
	num := runtime.NumCPU()
	fmt.Println(num)
	runtime.GOMAXPROCS(num)
	fmt.Println("num:=", num)
}
