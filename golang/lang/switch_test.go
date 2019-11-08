package switch_test

import (
	"fmt"
	"testing"

	check "gopkg.in/check.v1"
)

func Test(t *testing.T) {
	check.TestingT(t)
}

type SwitchSuit struct{}

var _ = check.Suite(&SwitchSuit{})

func (s *SwitchSuit) TestFall(c *check.C) {
	i := 2
	switch {
	case i == 1:
		fmt.Println(1)
	case i == 2:
		fmt.Println(2)
		fallthrough
	case i == 3:
		fmt.Println(3)
	}
}
