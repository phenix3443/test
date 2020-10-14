package lang

import "testing"

func TestFormat(t *testing.T) {
	t.Logf("%v", []int{1, 2, 3, 4})
	t.Logf("%#v", []int{1, 2, 3, 4})
	t.Logf("%T", []int{1, 2, 3, 4})

	// slice
	s := []int{1, 2, 3, 4}
	t.Logf("slice address=%p, slice 0th element address=%p", &s, s)
}
