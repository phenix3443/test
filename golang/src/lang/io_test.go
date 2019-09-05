// -*- coding:utf-8 -*-
// author:liushangliang
// desc: IO接口测试

package main

import (
	"fmt"
	"testing"

	. "gopkg.in/check.v1"
)

func Test(t *testing.T) {
	TestingT(t)
}

type IOTest struct{}

var _ = Suite(&IOTest{})

func (s *IOTest) TestHelloWorld(c *C) {
	fmt.Println("Hello.world!")
}
