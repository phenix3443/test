package mytest

import (
	"testing"
	"unsafe"
)

type EmptyStruct struct{}
type A struct {
	a int
}

// 测试 struct 的 size 大小
func TestEmptyStructSize(t *testing.T) {
	// https://blog.csdn.net/qq_34777600/article/details/87195673
	s := EmptyStruct{}
	t.Logf("empty struct size: %d", unsafe.Sizeof(s))
}

// 两个空结构体对象地址相同
func TestEmptyStructAddr(t *testing.T) {
	s1 := EmptyStruct{}
	s2 := EmptyStruct{}
	t.Logf("&s1=&s2:%t", &s1 == &s2) // false
}

// 比较结构体对象
func TestCmp(t *testing.T) {
	s1 := A{1}
	s2 := s1
	t.Logf("%t", s1 == s2)
}
