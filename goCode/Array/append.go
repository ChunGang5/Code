package main

import "fmt"

func main() {
	var nums = [...]int{1, 2, 3, 4, 5}
	var slice1 = nums[1:3]

	var slice2 []int = make([]int, 5, 10)
	slice2[0] = 10
	slice2[3] = 20
	slice1 = append(slice1, 30)
	var slice3 []int = make([]int, 10, 10)
	copy(slice3, slice1)

	fmt.Println(nums)
	fmt.Println(slice2)
	fmt.Println(slice3)
}
