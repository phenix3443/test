package basic_test

import (
	"fmt"
	"testing"
	"time"

	"github.com/dgraph-io/ristretto"
)

type Person struct {
	name string
}

func TestBasic(t *testing.T) {
	cache, err := ristretto.NewCache(&ristretto.Config{NumCounters: 1e7, MaxCost: 1 << 20, BufferItems: 64})
	if err != nil {
		panic(err)
	}

	key := "string"
	cache.Set(key, "string", 1)
	time.Sleep(time.Millisecond)
	value, found := cache.Get(key)
	if !found {
		panic("missing valude")
	}
	fmt.Println(value)
	cache.Del(key)

	p := Person{"john"}
	key = "struct"
	cache.Set(key, &p, 1)
	time.Sleep(time.Millisecond)
	value, found = cache.Get(key)
	if !found {
		panic("struct not found")
	}
	fmt.Println(value.(*Person).name)
}
