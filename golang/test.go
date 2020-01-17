package main

import "fmt"

func main() {
	a := []int{1, 2, 3, 4, 5}
	fmt.Println(a)
	b := make([]int, 0, len(a))
	b = append(append(append(b, a[2:3]...), a[0:2]...), a[3:len(a)]...)
	fmt.Println(b)
	fmt.Printf("hello")
}
