package rand_test

import (
	"fmt"
	"math/rand"
	"testing"

	check "gopkg.in/check.v1"
)

func Test(t *testing.T) {
	check.TestingT(t)
}

type RandSuit struct{}

var _ = check.Suite(&RandSuit{})

func (s *RandSuit) testRand(t *testing.T) {
	for i := 1; i < 10; i++ {
		fmt.Println(rand.Intn(10))
	}
}

func (s *RandSuit) testPerm(t *testing.T) {
	arr := rand.Perm(5)
	fmt.Println(arr)
}
