package mytest

import (
	"fmt"
	"testing"
)

// 测试没有 map 中不存在时返回 value_type 的零值
func TestMap(t *testing.T) {
	m := make(map[string]bool, 0)
	fmt.Printf("%v", m["test"])
}
