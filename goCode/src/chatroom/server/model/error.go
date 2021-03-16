package model

import "errors"

var (
	ERROR_USER_NOTEXIST = errors.New("用户不存在...")
	ERROR_USER_EXIST    = errors.New("用户已经存在，请勿重复注册...")
	ERROR_USER_RWD      = errors.New("密码不正确")
)