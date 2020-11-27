package main

import (
	"fmt"
	"math"
)

func main(){
	/*
	fmt.Println("test")
	var num int=10
	if num<15 {
		fmt.Println("too letter")
	}

	var years int
	fmt.Scanf("%d",&years)
	if (years%4==0 && years%100!=0)||years%400==0{
		fmt.Println("闰年")
	}
	*/

	var a,b,c float64
	fmt.Scanf("%f,%f,%f",a,b,c)

	m:=b*b-4*a*c

	if m>0{
		x1:=(-b+math.Sqrt(m))/2*a
		x2:=(-b-math.Sqrt(m))/2*a
		fmt.Printf("x1=%v,x2=%v\n",x1,x2)
	}else if m == 0{
		x:=(-b+math.Sqrt(m))/2*a
		fmt.Printf("x=%v\n",x)
	}else{
		fmt.Println("NO")
	}

}
