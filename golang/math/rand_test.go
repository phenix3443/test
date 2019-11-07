package rand_test

import (
	"fmt"
	"math/rand"
	"strings"
	"testing"
	"time"

	check "gopkg.in/check.v1"
)

func Test(t *testing.T) {
	check.TestingT(t)
}

type RandSuit struct{}

var _ = check.Suite(&RandSuit{})

func (s *RandSuit) TestInt(c *check.C) {
	fmt.Println(rand.Int())
	fmt.Println(rand.Int())
	fmt.Println(rand.Int())
}

func (s *RandSuit) TestIntn(c *check.C) {
	fmt.Println(rand.Intn(10))
	fmt.Println(rand.Intn(10))
	fmt.Println(rand.Intn(10))
}

func (s *RandSuit) TestPerm(c *check.C) {
	arr := rand.Perm(5)
	c.Assert(arr, check.HasLen, 5)
	fmt.Println(arr)
}

func (s *RandSuit) TestSeed(c *check.C) {
	rand.Seed(time.Now().UTC().UnixNano())
	fmt.Println(rand.Intn(10))
	fmt.Println(rand.Intn(10))
	fmt.Println(rand.Intn(10))
}

func (s *RandSuit) TestShuffle(c *check.C) {
	rand.Seed(time.Now().UTC().UnixNano())
	words := strings.Fields("ink runs from the corners of my mouth")
	rand.Shuffle(len(words), func(i, j int) {
		words[i], words[j] = words[j], words[i]
	})
	fmt.Println(words)
}
