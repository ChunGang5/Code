package main

import (
	"time"

	"github.com/garyburd/redigo/redis"
)

var pool *redis.Pool

func initPool(adderss string, maxIdle int, maxActive int, idleTimeout time.Duration) {
	pool = &redis.Pool{
		MaxIdle:     maxIdle,     //最大空闲连接数
		MaxActive:   maxActive,   //表示和数据库得最大连接数，0表示没有限制
		IdleTimeout: idleTimeout, //最大空闲时间
		Dial: func() (redis.Conn, error) {
			return redis.Dial("tcp", adderss)
		},
	}
}
