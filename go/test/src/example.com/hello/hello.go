package main

import (
	"fmt"
	"time"
)

type Element interface{}
type semaphore chan Element

func (s semaphore) P(n int) {
	for i := 0; i < n; i++ {
		s <- new(Element)
	}
}

func (s semaphore) V(n int) {
	for i := 0; i < n; i++ {
		<-s
	}
}

func getData(ch chan string) {
	time.Sleep(1e9)
	ch <- "done"
}
func main() {
	ch := make(chan string, 10)
	go getData(ch)
	fmt.Println(<-ch)
}
