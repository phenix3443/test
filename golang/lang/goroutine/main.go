package main

import (
	"fmt"
	"sync"
)

func send(wg *sync.WaitGroup, ch chan string) {
	ch <- "hello,"
	ch <- "world"
	wg.Done()
}

func recv(wg *sync.WaitGroup, ch chan string) {
	for str := range ch {
		fmt.Println(str)
		wg.Done()
	}
}

func main() {
	ch := make(chan string)
	defer close(ch)
	var wg sync.WaitGroup

	wg.Add(1)
	go send(&wg, ch)

	wg.Add(1)
	go recv(&wg, ch)

	wg.Wait()

	fmt.Println("main done")
}
