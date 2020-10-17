package mytest

import (
	"sync"
	"testing"
	"time"
)

//测试 select 使用
func TestSelect(t *testing.T) {
	var wg sync.WaitGroup
	ch1 := func() chan string {
		wg.Add(1)
		ch := make(chan string)
		go func() {
			// defer close(ch)
			defer wg.Done()
			time.Sleep(time.Second)
			ch <- "function 1 wake up"
		}()
		return ch
	}()
	ch2 := func() chan string {
		wg.Add(1)
		ch := make(chan string)
		go func() {
			// defer close(ch)
			defer wg.Done()
			time.Sleep(2 * time.Second)
			ch <- "function 2 wake up"

		}()
		return ch
	}()

	quit := false

	for !quit {
		select {
		case v, ok := <-ch1:
			if ok {
				t.Log(v)
			}

		case v, ok := <-ch2:
			if ok {
				t.Log(v)
				quit = true
			}
		}
	}
	t.Log("main end")
}
