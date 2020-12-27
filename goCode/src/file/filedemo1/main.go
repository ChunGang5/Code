package main

import (
	"fmt"
	"os"
)

// func main() {
// 	file, err := os.Open("d:/test.txt")
// 	if err != nil {
// 		fmt.Println("open file error")
// 	}
// 	//代码将要执行完时，开始执行defer后的代码，防止内存泄漏
// 	defer file.Close()

// 	readbuf := bufio.NewReader(file)
// 	for {
// 		str, err := readbuf.ReadString('\n')
// 		if err == io.EOF {
// 			break
// 		}
// 		fmt.Println(str)
// 	}
// 	fmt.Println("文件读取结束")
// }

// fmt.Printf("file: %T->%v", file, file)
// err = file.Close()
// if err != nil {
// 	fmt.Println("close file error")
// }

//写文件操作

// func main() {
// 	filePath := "d:/abc.txt"
// 	file, err := os.OpenFile(filePath, os.O_WRONLY|os.O_CREATE, 0666)
// 	if err != nil {
// 		fmt.Printf("open file err=%v", err)
// 		return
// 	}
// 	defer file.Close()
// 	str := "hello file\n"
// 	writer := bufio.NewWriter(file)
// 	for i := 0; i < 3; i++ {
// 		writer.WriteString(str)
// 	}
// 	writer.Flush()
// }

// func main() {
// 	filePath := "d:/abc.txt"
// 	file, err := os.OpenFile(filePath, os.O_RDWR|os.O_APPEND, 0666)
// 	if err != nil {
// 		fmt.Printf("open file error: %v\n", err)
// 		return
// 	}
// 	defer file.Close()
// 	reader := bufio.NewReader(file)
// 	for {
// 		str, err := reader.ReadString('\n')
// 		if err == io.EOF {
// 			break
// 		}
// 		//输出到显示器上，因为是带缓冲的输出
// 		fmt.Print(str)
// 	}
// 	str := "一身都是月!\n"
// 	writer := bufio.NewWriter(file)
// 	for i := 0; i < 5; i++ {
// 		writer.WriteString(str)
// 	}
// 	writer.Flush()
// }

// func main() {
// 	filePath1 := "d:/abc.txt"
// 	filePath2 := "d:/kkk.txt"
// 	data, err := ioutil.ReadFile(filePath1)
// 	if err != nil {
// 		fmt.Printf("read file error: %v\n", err)
// 		return
// 	}
// 	err = ioutil.WriteFile(filePath2, data, 0666)
// 	if err != nil {
// 		fmt.Printf("write file error: %v\n", err)
// 	}
// }

//判断文件是否存在
func PathExists(path string) (bool, error) {
	_, err := os.Stat(path)
	if err == nil {
		return true, nil
	} else if os.IsNotExist(err) {
		return false, nil
	} else {
		return false, err
	}
}
func main() {
	pathFile := "d:/aija.txt"
	falg, err := PathExists(pathFile)
	if falg == true && err == nil {
		fmt.Println("文件存在")
	} else if falg == false && err == nil {
		fmt.Println("文件不存在")
	} else {
		fmt.Println("不能确定！")
	}
}
