package main

import "fmt"

/*
func main() {
	var days int = 97
	var week int = days / 7
	var day int = days % 7
	fmt.Printf("%d weeks and %d day\n", week, day)
}
*/
func Add(a int, b int) int {
	return a + b
}
func main() {
	a := 1
	b := 2
	/*
		a, b = b, a
		var tmp int
		tmp = a
		a = b
		b = tmp
	*/

	fmt.Printf("a=%d,b=%d\n", a, b)

}
