// -*- coding:utf-8; -*-
package mymath

import "testing"

func TestAdd(t *testing.T) {
	sum := add(1, 2)
	if sum != 3 {
		t.Error("加法错误")
	}
}
