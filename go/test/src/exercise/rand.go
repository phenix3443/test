package main

import (
	"fmt"
	"math/rand"
)

func testRand() {
	for i := 1; i < 10; i++ {
		fmt.Println(rand.Intn(10))
	}
}
