package lang

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

func TestSize(*testing.T) {
	// https://blog.csdn.net/qq_34777600/article/details/87195673
	var str string
	fmt.Println(unsafe.Sizeof(str))
	var s struct{}
	fmt.Println(unsafe.Sizeof(s))
	x := make([]struct{}, 0, 100)
	fmt.Printf("size=%d,len=%d,cap=%d\n", unsafe.Sizeof(x), len(x), cap(x))
}

// go test -run Add
func TestAddr(*testing.T) {
	s1 := struct{}{}
	s2 := struct{}{}
	fmt.Printf("&s1=%p,&s2=%p,&s1=&s2:%t\n", &s1, &s2, &s1 == &s2)
}

func TestCmp(*testing.T) {
	type A struct {
		a int
	}
	s1 := A{1}
	s2 := s1

	fmt.Printf("%t", s1 == s2)
}
