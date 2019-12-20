package main

import (
	"fmt"

	"github.com/golang-collections/collections/set"
)

func wrapFunc(e interface{}) { fmt.Println(e) }

func main() {
	a := []interface{}{1, 2, 3, 4}
	s := set.New(a...)
	if s.Has(3) {
		fmt.Println("has 3 in set")
	}
	// 测试do函数
	s.Do(wrapFunc)
}
