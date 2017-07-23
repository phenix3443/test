package main

import (
	// "fmt"
	"log"
	"runtime"
)

func main() {
	where()
}

func where() {
	_, file, line, _ := runtime.Caller(1)
	log.Printf("%s:%d", file, line)
}
