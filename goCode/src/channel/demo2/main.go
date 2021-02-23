package main

import (
	"fmt"
	"time"
)

/*
func writeData(message chan int) {
	for i := 1; i <= 50; i++ {
		message <- i
		fmt.Printf("写入数据：%d\n", i)
	}
	close(message)
}
func readData(message chan int, flag *bool) {
	for {
		v, ok := <-message
		if !ok {
			break
		}
		fmt.Printf("读到数据：%d\n", v)
	}
	*flag = true
}
func main() {
	var message chan int
	message = make(chan int, 50)
	//flag := make(chan bool, 1)
	flag := false

	go writeData(message)
	//go readData(message, flag)
	go readData(message, &flag)
	for {
		if flag {
			break
		}
	}
	fmt.Printf("v is : %v\n", flag)
}
*/
func pushNum(intChan chan int) {
	for i := 1; i <= 8000; i++ {
		intChan <- i
	}
	close(intChan)
}
func primeNum(intChan chan int, primeChan chan int, exitChan chan bool) {
	//var num int
	var flag bool
	for {
		num, ok := <-intChan
		if !ok {
			break
			//写入操作完成，close(intChan),并且已经被读完，直接退出
		}
		flag = true
		for i := 2; i < num; i++ {
			if num%i == 0 {
				flag = false
				break
			}
		}

		if flag == true {
			primeChan <- num
		}
	}
	fmt.Println("有一个primeNum协程取不到数据退出")
	//但是可能还有其他协程已经之前去到数据正在处理，不能关闭primechan
	exitChan <- true
}
func main() {
	intChan := make(chan int, 8000)
	primeChan := make(chan int, 5000)
	exitChan := make(chan bool, 16)

	start := time.Now().Unix()
	go pushNum(intChan)

	for i := 1; i <= 16; i++ {
		go primeNum(intChan, primeChan, exitChan)
	}

	// for i := 1; i <= 4; i++ {
	// 	<-exitChan
	// }
	// close(primeChan)
	var lenNum int
	lenNum = 0
	go func() {
		for i := 1; i <= 16; i++ {
			<-exitChan
		}
		end := time.Now().Unix()
		fmt.Printf("times is %v\n", end-start)
		close(primeChan)
		//lenNum = len(primeChan)放这块也不行，统计不到确定数字
	}()
	//lenNum = len(primeChan),放这块不行，主线程在没有close（primeChan)之前一直在边拿边取
	//fmt.Printf("素数总数为：%d\n", len(primeChan))
	//遍历
	for {
		v, ok := <-primeChan
		if !ok {
			break
		}
		fmt.Printf("素数:=%d\n", v)
		lenNum++
	}
	fmt.Println("主线程退出")
	//fmt.Printf("素数总数为：%d\n", lenNum)
}
