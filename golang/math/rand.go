package my_rand_test

import (
	"fmt"
	"math/rand"
	"testing"

	"gopkg.in/check.v1"
)

func Test(t *testing.T) {
	check.TestingT(t)
}

type RandSuit struct{}

var _ = check.Suite(&RandSuit{})

func (s *RandSuit) TestRand(c *check.C) {
	for i := 1; i < 10; i++ {
		fmt.Println(rand.Intn(10))
	}
}

func (s *RandSuit) TestPerm(c *check.C) {
	arr := rand.Perm(5)
	fmt.Println(arr)
}
