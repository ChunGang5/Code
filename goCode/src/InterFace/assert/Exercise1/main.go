package main

import "fmt"

type Student struct {
	name string
}

func TypeJudge(items ...interface{}) {
	for index, x := range items {
		switch x.(type) {
		case bool:
			fmt.Printf("第%v个参数是bool类型，值是%v\n", index, x)
		case float32:
			fmt.Printf("第%v个参数是bool类型，值是%v\n", index, x)
		case Student:
			fmt.Printf("第%v个参数是Student类型，值是%v\n", index, x)

		case *Student:
			fmt.Printf("第%v个参数是*Student类型，值是%v\n", index, x)
		default:
			fmt.Printf("第%v个参数是类型不确定，值是%v\n", index, x)
		}
	}
}
func main() {
	var n1 float32 = 31.2
	var n2 bool = true
	var s1 Student = Student{"chengang"}
	var s2 *Student = new(Student)
	(*s2).name = "cawd"

	TypeJudge(n1, n2, s1, s2)
}
