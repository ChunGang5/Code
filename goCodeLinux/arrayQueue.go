package main
import (
	"fmt";
	"errors"
	"os"
)

type Queue struct{
	maxSize int;
	array [5]int;
	front int;
	rear int;
}
func (this *Queue)addQueue(val int)(err error){
	if this.rear==this.maxSize-1{
		return errors.New("queue full!")
	}
	this.rear++
	this.array[this.rear]=val
	return
}
func (this *Queue)getQueue()(val int,err error){
	//判断队列是否为空
	if this.front==this.rear{
		return -1,errors.New("queue empty!")
	}
	this.front++
	val=this.array[this.front]
	return val,err;
}
func (this *Queue)showQueue(){
	fmt.Println("显示队列元素.....")
	for i:=this.front+1;i<=this.rear;i++{
		fmt.Printf("array[%d]=%d\t",i,this.array[i])
	}
	fmt.Println();
}
func main(){
	queue:=Queue{
		maxSize:5,
		front:-1,
		rear:-1,
	}
	var key string
	var val int
	for {
		fmt.Println("1.输入add添加数据到队列")
		fmt.Println("2.输入get从队列中获取元素")
		fmt.Println("3.输入show表示显示队列")
		fmt.Println("4.输入exit退出并显示队列")
		fmt.Scanln(&key)
		switch key{
			case "add":
				fmt.Println("输入要入队的元素")
				fmt.Scanln(&val)
				err:=queue.addQueue(val)
				if err!=nil{
					fmt.Println(err.Error())
				}else{
					fmt.Println("加入元素成功")
				}
			case "get":
				val,err:=queue.getQueue()
				if err!=nil{
					fmt.Println(err)
				}else{
					fmt.Printf("从队列里取出来一个数：%d\n",val)
				}
			case "show":
				queue.showQueue()
			case "exit":
				queue.showQueue()
				os.Exit(0)
		}
	}
}
