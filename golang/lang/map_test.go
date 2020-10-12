package lang

import (
	"fmt"
	"testing"
)

func TestMap(t *testing.T) {
	m := make(map[string]bool, 0)
	fmt.Printf("%v", m["test"])
}
