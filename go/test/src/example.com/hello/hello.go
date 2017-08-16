package main

import (
	"fmt"
	"reflect"
)

func main() {
	var i int
	fmt.Println(reflect.TypeOf(i), i) // int 0
	var f float32
	fmt.Println(reflect.TypeOf(f), f) // float32 0
	var b byte
	fmt.Println(reflect.TypeOf(b), b) // uint8 0
	var r rune
	fmt.Println(reflect.TypeOf(r), r) // int32 0
	var s string
	fmt.Println(reflect.TypeOf(s), s) // string
	var arr1 [5]int
	fmt.Println(reflect.TypeOf(arr1), arr1) // [5]int [0 0 0 0 0]
	var arr2 = new([5]int)
	fmt.Println(reflect.TypeOf(arr2), arr2) // *[5]int &[0 0 0 0 0]
	var arr3 = *arr2
	arr3[2] = 100
	fmt.Println(arr2, arr3) // &[0 0 0 0 0] [0 0 100 0 0]
	var slice []int
	fmt.Println(reflect.TypeOf(slice), slice) // []int []
	var fun = func() {}
	fmt.Println(reflect.TypeOf(fun)) // func()
}
