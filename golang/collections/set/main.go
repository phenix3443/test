package main

import (
	"fmt"

	"github.com/golang-collections/collections/set"
)

func main() {
	s := set.New(1, 2, 3, 4)
	if s.Has(3) {
		fmt.Println("has")
	}
}
