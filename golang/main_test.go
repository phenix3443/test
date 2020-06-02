package test

import (
	"fmt"
	"testing"
	"unsafe"
)

// func TestSliceSpace(t *testing.T) {
// 	var s1 []int
// 	s2 := []int{}
// 	fmt.Printf("s1=%p,s2=%p\n", s1, s2) // s1=0x0,s2=0x1268f58
// }

func TestB(*testing.T) {
	var s string
	fmt.Println(unsafe.Sizeof(s))
}
