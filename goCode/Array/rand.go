package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	var nums [5]int
	len := len(nums)
	rand.Seed(time.Now().UnixNano())

	for i := 0; i < len; i++ {
		nums[i] = rand.Intn(100)
	}

	fmt.Println(nums)

	temp := 0

	for i := 0; i < len/2; i++ {
		temp = nums[len-1-i]
		nums[len-1-i] = nums[i]
		nums[i] = temp
	}
	fmt.Println(nums)
}
