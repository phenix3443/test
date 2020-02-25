package main

import (
	"fmt"
	"time"
)

func send(ch chan string) {
	ch <- "hello,"
	ch <- "world"
}

func recv(ch chan string) {
	for str := range ch {
		fmt.Println(str)
	}
}
func main() {
	ch := make(chan string)
	go send(ch)
	go recv(ch)

	t, _ := time.ParseDuration("10s")
	time.Sleep(t)
	fmt.Println("main done")
}
