package main

import (
	"fmt"
)

/*
var (
	Map  = make(map[int]int, 201)
	lock sync.Mutex
)

func test(n int) {
	res := 1
	for i := 1; i <= n; i++ {
		res *= i
	}
	lock.Lock()
	Map[n] = res
	lock.Unlock()
}
func main() {
	for i := 1; i <= 200; i++ {
		go test(i)
	}
	time.Sleep(time.Second * 5)
	lock.Lock()
	for i, v := range Map {
		fmt.Printf("Map[%d]=%d\n", i, v)
	}
	lock.Unlock()
}


func main() {
	go spinner(100 * time.Millisecond)
	const n = 45
	fibN := fib(n) // slow
	fmt.Printf("\rFibonacci(%d) = %d\n", n, fibN)
}

func spinner(delay time.Duration) {
	for {
		for _, r := range `-\|/` {
			fmt.Printf("\r%c", r)
			time.Sleep(delay)
		}
	}
}

func fib(x int) int {
	if x < 2 {
		return x
	}
	return fib(x-1) + fib(x-2)
}


func main() {
	var intChan chan int
	intChan = make(chan int, 3)
	intChan <- 10
	intChan <- 20
	intChan <- 30
	num1 := <-intChan
	intChan <- 40
	fmt.Printf("intChan len is :%v,cap is:%v, num1=%d\n", len(intChan), cap(intChan), num1)

	var mapChan chan map[string]string
	mapChan = make(chan map[string]string, 10)
	m1 := make(map[string]string, 5)
	m1["c1"] = "北京"
	m1["c2"] = "上海"
	mapChan <- m1
	//mapChan<-m1
	fmt.Printf("len is %v, cap is %v\n", len(mapChan), cap(mapChan))
	m2 := make(map[string]string, 5)
	fmt.Printf("m2 len is %v, cap is %v\n", len(m2), len(m2))
	m2 = <-mapChan
	fmt.Printf("m2 len is %v, cap is %v\n", len(m2), len(m2))
}



var Person(
	Name string
	Age int
	Adderss string
)
func main(){
	var personChan chan Person
	personChan=make(chan Person,10)

}
*/

func main() {
	var intChan chan int
	intChan = make(chan int, 200)
	for i := 1; i <= 100; i++ {
		res := i * 2
		intChan <- res
	}
	close(intChan)
	for val := range intChan {
		fmt.Printf("v=%d\n", val)
	}
}
