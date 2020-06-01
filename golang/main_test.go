package test

import (
	"fmt"
	"strings"
	"testing"
)

// func TestSliceSpace(t *testing.T) {
// 	var s1 []int
// 	s2 := []int{}
// 	fmt.Printf("s1=%p,s2=%p\n", s1, s2) // s1=0x0,s2=0x1268f58
// }

func TestB(*testing.T) {
	for i := 0; i < 10; i++ {
		fmt.Println(strings.Repeat("G", i))

	}

}
