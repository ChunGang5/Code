package main

import "fmt"

func main() {
	var arr [5]int32 = [5]int32{1, -1, 9, 90, 12}
	var sum int32 = 0
	for _, val := range arr {
		sum += val
	}
	fmt.Printf("%d\n", int32(sum)/int32(len(arr)))

}
