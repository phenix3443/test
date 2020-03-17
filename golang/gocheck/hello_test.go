package hello_test

import (
	"testing"

	. "gopkg.in/check.v1"
)

func Test(t *testing.T) { TestingT(t) }

type MySuite struct{}

var _ = Suite(&MySuite{})

func (s *MySuite) TestHello(c *C) {
	c.Check(42, Equals, "42")
	c.Assert(41, Equals, "42")
	c.Check(42, Equals, 42)
}
