package main

import (
	"fmt"
	"sort"
	//"math/rand"
)

/*
type Hero struct{
	Name string
	Age int
}
type HeroSlice []Hero
func (hs HeroSlice)Len()int{
	return len(hs)
}
//按照年龄由大到小排序
func (hs HeroSlice)Less(i,j int)bool{
	return hs[i].Age<hs[j].Age
}
*/

func main() {
	var s []int = []int{0, 3, 4, 2, 6, 8, 1, 25, 449}
	sort.Ints(s)
	fmt.Println(s)
}
