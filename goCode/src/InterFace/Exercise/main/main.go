package main

import (
	"fmt"
	//"math/rand"
	//"sort"
)

// type Hero struct {
// 	Name string
// 	Age  int
// }
// type HeroSlice []Hero

// func (hs HeroSlice) Len() int {
// 	return len(hs)
// }

// //按照年龄由大到小排序
// func (hs HeroSlice) Less(i, j int) bool {
// 	return hs[i].Age < hs[j].Age
// }

// func (hs HeroSlice) Swap(i, j int) {
// 	//常规交换
// 	/*temp:=hs[i]
// 	hs[i]=hs[j]
// 	hs[j]=temp*/
// 	//Go语言新特性
// 	hs[i], hs[j] = hs[j], hs[i]
// }

// func main() {
// 	var s []int = []int{0, 3, 4, 2, 6, 8, 1, 25, 449}
// 	sort.Ints(s)
// 	fmt.Println(s)

// 	var heros HeroSlice
// 	for i := 0; i < 10; i++ {
// 		hero := Hero{
// 			Name: fmt.Sprintf("英雄:%d", rand.Intn(100)),
// 			Age:  rand.Intn(100),
// 		}
// 		heros = append(heros, hero)
// 	}

// 	for _, val := range heros {
// 		fmt.Println(val)
// 	}

// 	sort.Sort(heros)
// 	fmt.Println("排序后")
// 	for _, val := range heros {
// 		fmt.Println(val)
// 	}
// }

type Mokey struct {
	Name string
}

//声明接口
type BirdAble interface {
	Flying()
}
type FishAble interface {
	Swimming()
}

func (m Mokey) climbing() {
	fmt.Println("生来会爬树")
}

type LitterMokey struct {
	Mokey
	//Age int
}

func (this LitterMokey) Flying() {
	fmt.Println("小猴子学会飞翔了")
}
func (this LitterMokey) Swimming() {
	fmt.Println("小猴子学会游泳了")
}

func main() {
	mokey := LitterMokey{
		Mokey{
			Name: "孙悟空",
		},
		//Age: 5,
	}
	mokey.climbing()
	mokey.Flying()
	mokey.Swimming()
}
