package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() {
	file, err := os.Open("d:/test.txt")
	if err != nil {
		fmt.Println("open file error")
	}
	//代码将要执行完时，开始执行defer后的代码，防止内存泄漏
	defer file.Close()

	readbuf := bufio.NewReader(file)
	for {
		str, err := readbuf.ReadString('\n')
		if err == io.EOF {
			break
		}
		fmt.Println(str)
	}
	fmt.Println("文件读取结束")
}

// fmt.Printf("file: %T->%v", file, file)
// err = file.Close()
// if err != nil {
// 	fmt.Println("close file error")
// }
