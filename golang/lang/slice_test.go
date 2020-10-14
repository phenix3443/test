package lang

import (
	"testing"
)

// 验证两个问题：
// 1. s 是值传递
// 2. slice resize 后会修改底层的洞动态数组
func add(t *testing.T, s []int) {
	t.Logf("in func, befor resize, s 0th element addr=%p", s)
	s[0] = 3 //修改原有数据
	s[1] = 4
	for i := 0; i < 10; i++ {
		s = append(s, i) // resize导致s不再指向原来分配到内存
	}
	t.Logf("in func, after resize, s 0th element addr=%p", s)

	t.Logf("in func, aftere resize, s=%v", s)
}

// 测试 slice 作为参数传递时候的坑
func TestResize(t *testing.T) {
	s := make([]int, 2, 2)
	s[0] = 1
	s[1] = 2
	t.Logf("out func before call, s addr=%p, value=%v", s, s)
	add(t, s)
	t.Logf("out func after call, s addr=%p, value=%v", s, s)
}
