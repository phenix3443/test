package mytest

import (
	"testing"
	"time"
)

// 测试阻塞型 channel 生产者和消费者的执行顺序
func TestBlockedChannel(t *testing.T) {
	ch := make(chan int)
	go func() {
		defer close(ch)
		t.Log("send start")
		ch <- 100
		t.Log("send stop")
	}()

	go func() {
		t.Log("recv start")
		time.Sleep(time.Microsecond)
		i := <-ch
		t.Logf("recv stop, received: %d", i)
	}()

	time.Sleep(time.Second)
	t.Log("test done")
}

// 测试 for...range 和channel使用

func TestForRangeChannel(t *testing.T) {
	ch := make(chan int)
	go func() {
		// defer close(ch) //这里好像也不是必须是要手动关闭ch？
		t.Log("send start")
		for i := 0; i < 10; i++ {
			ch <- i
		}
		t.Log("send stop")
	}()

	go func() {
		t.Log("recv start")
		for c := range ch {
			t.Logf("recved:%d", c)
		}
		t.Log("recv stop")
	}()
	time.Sleep(time.Second)
	t.Log("test done")
}
