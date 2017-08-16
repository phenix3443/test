package main

import (
	"fmt"
)

func main() {
	// var i int
	// fmt.Println(reflect.TypeOf(i), i) // int 0
	// var f float32
	// fmt.Println(reflect.TypeOf(f), f) // float32 0
	// var b byte
	// fmt.Println(reflect.TypeOf(b), b) // uint8 0
	// var r rune
	// fmt.Println(reflect.TypeOf(r), r) // int32 0
	// var s string
	// fmt.Println(reflect.TypeOf(s), s) // string
	// var arr1 [5]int
	// fmt.Println(reflect.TypeOf(arr1), arr1) // [5]int [0 0 0 0 0]
	// var slice []int
	// fmt.Println(reflect.TypeOf(slice), slice) // []int []
	// var m map[string]int
	// fmt.Println(reflect.TypeOf(m), m) // map[string]int map[]
	// var fun = func() {}
	// fmt.Println(reflect.TypeOf(fun)) // func()

	m := new(map[string]string)
	(*m)["hello"] = "world"
	fmt.Println(m)
}
