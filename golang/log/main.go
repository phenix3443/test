package main

import (
	"bytes"
	"fmt"
	"log"
)

func main() {
	log.SetFlags(log.Lshortfile | log.Ldate | log.Ltime)
	log.SetPrefix("standard log prefix:")
	log.Printf("hello,world")

	var buf bytes.Buffer
	logger := log.New(&buf, "logger prefix:", log.LstdFlags)
	logger.Printf("log by logger and save in buffer")
	fmt.Print(&buf)
}
