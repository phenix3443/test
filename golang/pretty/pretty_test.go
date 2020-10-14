package pretty_test

import (
	"testing"

	"github.com/kr/pretty"
)

func TestPretty(t *testing.T) {
	type Person struct {
		name string
		age  int
	}
	a := Person{"tom", 1}
	b := Person{"jary", 2}
	t.Logf("%v", pretty.Diff(a, b))

	t.Logf("%v", pretty.Diff([]int{1, 2, 3}, []int{1, 2}))
}
