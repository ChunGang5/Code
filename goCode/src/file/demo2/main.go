package main

import (
	"fmt"
	"os"
)

func main() {
	file, err := os.Open("d:/test.txt")
	if err != nil {
		fmt.Println("file open error")
	} else {
		fmt.Println("open success")
	}
	file.Close()
}
