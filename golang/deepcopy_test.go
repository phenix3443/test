package mytest

import (
	"testing"

	"github.com/antlabs/deepcopy"
)

func TestPointerCopy(t *testing.T) {
	type A struct {
		P *[]int
	}

	src := A{&[]int{1}}
	var dst A
	deepcopy.Copy(&dst, &src).Do()
	(*dst.P)[0] = 2 // panic here
	t.Logf("src=%v,dst=%v", src, dst)

	if (*src.P)[0] == (*dst.P)[0] {
		t.Fail()
	}
}
