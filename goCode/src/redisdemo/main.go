package main

import (
	"fmt"

	"github.com/garyburd/redigo/redis"
)

/*
func main() {
	conn, err := redis.Dial("tcp", "127.0.0.1:6379")
	if err != nil {
		fmt.Println("redis connect error: ", err)
		return
	}
	defer conn.Close()

	//存数据
	_, err = conn.Do("set", "key1", 1024)
	if err != nil {
		fmt.Println("set error: ", err)
		return
	}

	//取数据
	r, err := redis.String(conn.Do("get", "key1")) //r返回的值是interface{}，所以需要断言来转换

	if err != nil {
		fmt.Println("get error: ", err)
		return
	}
	fmt.Println("操作成功，ok！", r)

}
*/

func main() {
	conn, err := redis.Dial("tcp", "127.0.0.1:6379")
	if err != nil {
		fmt.Println("connect error: ", err)
		return
	}
	defer conn.Close()
	_, err = conn.Do("hset", "user1", "name1", "chengang")
	if err != nil {
		fmt.Println("hset error: ", err)
		return
	}

	data, err := redis.String(conn.Do("hget", "user1", "name1"))
	if err != nil {
		fmt.Println("hget error: ", err)
		return
	}

	fmt.Println("success!", data)

	_, err = conn.Do("hmset", "user2", "name", "lkc", "age", 24)
	if err != nil {
		fmt.Println("hmset error: ", err)
		return
	}

	rs, err := redis.Strings(conn.Do("hmget", "user2", "name", "age"))
	if err != nil {
		fmt.Println("hmget error: ", err)
		return
	}

	for i, v := range rs {
		fmt.Printf("r[%d]=%s\n", i, v)
	}

}
