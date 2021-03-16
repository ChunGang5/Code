package main

import (
	"bufio"
	"fmt"
	"os"
)

type ValNode struct {
	row int
	col int
	val int
}

func main() {
	//1.先创建一个原始数组
	var chessMap [11][11]int
	chessMap[1][2] = 1 //1代表白子，2黑子、0空
	chessMap[2][3] = 2
	//2、查看原始数组
	for _, v1 := range chessMap {
		for _, v2 := range v1 {
			fmt.Printf("%d\t", v2)
		}
		fmt.Println()
	}
	var saprseArr []ValNode
	valNode := ValNode{
		row: 11,
		col: 11,
		val: 0,
	}

	saprseArr = append(saprseArr, valNode)

	for i, v1 := range chessMap {
		for j, v2 := range v1 {
			if v2 != 0 {
				valNode := ValNode{
					row: i,
					col: j,
					val: v2,
				}
				saprseArr = append(saprseArr, valNode)
			}
		}
	}

	fmt.Println("输出稀疏数组")
	for i, valNode := range saprseArr {
		fmt.Printf("%d:%d %d %d\n", i, valNode.row, valNode.col, valNode.val)
	}

	filePath := "d:/chessmap.data"
	file, err := os.OpenFile(filePath, os.O_WRONLY|os.O_CREATE, 0666)
	if err != nil {
		fmt.Println("file create error")
		return
	}
	defer file.Close()
	writer := bufio.NewWriter(file)
	for _, valNode := range saprseArr {
		str := fmt.Sprintf("%d %d %d\n", valNode.row, valNode.col, valNode.val)
		writer.WriteString(str)
	}
	writer.Flush()
	//从稀疏数组恢复原数组

	var chessMap2 [11][11]int
	for i, valNode := range saprseArr {
		if i != 0 {
			chessMap2[valNode.row][valNode.col] = valNode.val
		}
	}

	fmt.Println("稀疏数组恢复原数组后.....")
	for _, v1 := range chessMap2 {
		for _, v2 := range v1 {
			fmt.Printf("%d\t", v2)
		}
		fmt.Println()
	}
}
