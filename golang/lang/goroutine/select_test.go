package channel_test

import (
	"fmt"
	"sync"
	"testing"
	"time"
)

func f1(wg *sync.WaitGroup) (ch chan string) {
	ch = make(chan string)
	wg.Add(1)
	go func() {
		defer close(ch)
		defer wg.Done()
		time.Sleep(sleep1s)
		ch <- "function 1 wake up"
	}()
	return ch
}

func f2(wg *sync.WaitGroup) (ch chan string) {
	ch = make(chan string)
	wg.Add(1)
	go func() {
		defer close(ch)
		defer wg.Done()
		time.Sleep(sleep3s)
		ch <- "function 2 wake up"

	}()
	return ch
}

func f3(wg *sync.WaitGroup) (ch chan string) {
	ch = make(chan string)
	go func() {
		defer close(ch)
		wg.Wait()
		ch <- "function 3 wake up"
	}()
	return ch
}

func TestSelect(t *testing.T) {
	var wg sync.WaitGroup
	ch1 := f1(&wg)
	ch2 := f2(&wg)
	ch3 := f3(&wg)
	quit := true
	for quit {
		select {
		case v, ok := <-ch1:
			if ok {
				fmt.Println(v)
			}

		case v, ok := <-ch2:
			if ok {
				fmt.Println(v)
			}

		case v := <-ch3:
			fmt.Println(v)
			quit = false
		default:
			time.Sleep(sleep1ms)
		}

	}
	fmt.Println("main end")
}
