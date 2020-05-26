package slice_test

import (
	"fmt"
	"testing"
)

func add(s []int) {
	s[0] = 3
	s[1] = 4
	for i := 0; i < 100; i++ {
		s = append(s, i)
	}
	fmt.Printf("in add,%p,%v\n", s, len(s))
}

func TestResize(*testing.T) {
	s := make([]int, 2, 2)
	s[0] = 1
	s[1] = 2
	fmt.Printf("before add, %p,%v\n", s, s)
	add(s)
	fmt.Printf("after add, %p,%v\n", s, s)
}
