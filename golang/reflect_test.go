package mytest

import (
	"reflect"
	"testing"
)

type Person struct {
	Name string
	Age  uint
}

func TestGetStructName(t *testing.T) {
	p := Person{}
	typ := reflect.TypeOf(p)
	t.Logf("kind=%s,name=%s", typ.Kind(), typ.Name())

	i := 10
	typ = reflect.TypeOf(i)
	t.Logf("kind=%s,name=%s", typ.Kind(), typ.Name())
}
