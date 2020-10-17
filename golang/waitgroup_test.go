package mytest

import (
	"sync"
	"testing"
	"time"
)

func recv(wg *sync.WaitGroup, ch chan int) {

}

// 测试 waitgroup 使用，以及 chan 执行顺序
func TestWaitGroup(t *testing.T) {
	var wg sync.WaitGroup

	ch := func() chan int {
		wg.Add(1)
		ch := make(chan int)
		go func() {
			defer wg.Done()
			t.Log("send start")
			for i := 0; i < 10; i++ {
				ch <- i
				t.Logf("sended %d", i) // 这里阻塞
			}
			close(ch)
			t.Log("send end")
		}()

		return ch
	}()

	go func() {
		wg.Add(1)
		defer wg.Done()
		time.Sleep(time.Millisecond) // 等待 send 函数执行
		t.Log("recv start")
		for i := range ch {
			t.Logf("recv %d", i)
		}
		t.Log("recv end")

	}()

	wg.Wait()

	t.Log("main done after sleep")
}
