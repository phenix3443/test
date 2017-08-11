package main

import (
	"fmt"
)

func main() {
	fmt.Println("in main f1", f1())
	fmt.Println("in main f2", f2())
	fmt.Println("in main f3", f3())
}

// 非命名返回值
func f1() int {
	var a int
	defer func(x *int) {
		*x = 1
	}(&a)
	return a
}

// 命名参数，修改返回值
func f2() (y int) {
	var a int
	defer func(x *int) {
		*x = 2
	}(&a)
	return a
}

// 命名参数，修改命名参数
func f3() (y int) {
	var a int
	defer func(x *int) {
		*x = 3
	}(&y)
	return a
}

func f4() (y int) {
	defer func(x *int) {
		*x = 4
	}(&y)
	return
}
