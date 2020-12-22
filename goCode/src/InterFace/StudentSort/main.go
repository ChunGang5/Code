package main

import (
	"fmt"
	"math/rand"
	"sort"
)

type Student struct {
	Name  string
	Age   int
	Sex   string
	Score float64
}

type StuSlice []Student

func (stu StuSlice) Len() int {
	return len(stu)
}

func (stu StuSlice) Less(i, j int) bool {
	return stu[i].Score > stu[j].Score
}

func (stu StuSlice) Swap(i, j int) {
	stu[i], stu[j] = stu[j], stu[i]
}

func main() {
	var stuS StuSlice
	for i := 0; i < 10; i++ {
		stu := Student{
			Name:  fmt.Sprintf("%d", rand.Intn(1000)),
			Age:   rand.Intn(100),
			Sex:   "男",
			Score: rand.Float64(),
		}
		stuS = append(stuS, stu)
	}

	for _, val := range stuS {
		fmt.Println(val)
	}

	fmt.Println("排序后")

	sort.Sort(stuS)

	for _, val := range stuS {
		fmt.Println(val)
	}
}
