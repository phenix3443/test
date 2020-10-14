package lang

import (
	"testing"
	"time"
)

func blockedSend(t *testing.T) chan int {
	ch := make(chan int)

	go func() {
		defer close(ch)
		t.Log("send start")
		ch <- 100
		t.Log("send stop")
	}()

	return ch
}

func blockedRecv(t *testing.T, ch chan int) {
	t.Log("recv start")
	time.Sleep(time.Microsecond)
	i := <-ch
	t.Logf("recv stop, received: %d", i)
}

// 测试阻塞型 channel 生产者和消费者的执行顺序
func TestBlockedChannel(t *testing.T) {
	ch := blockedSend(t)
	go blockedRecv(t, ch)
	time.Sleep(time.Second)
	t.Log("test done")
}
