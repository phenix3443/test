package main

import (
	"fmt"
	"math"
)

func round(x float64) int {
	return int(math.Floor(x + 0.5))
}
func main() {
	fmt.Println(round(float64(3) * 0.5))
}
