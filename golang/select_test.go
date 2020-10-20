package mytest

import (
	"testing"
	"time"
)

func prodAndConuser(t *testing.T, chProducer, chConsumer chan int) {
	t.Log("start")
	var v int
	for {
		select {
		case v = <-chProducer:
			t.Logf("produce: v=%d", v)
			v++

		// case chConsumer <- v:
		// 	t.Logf("consumer: v=%d", v)
		default:
			t.Log("没有 channel 可以执行")
			time.Sleep(time.Millisecond * 500)
		}
	}
}

//测试 select 使用
func TestSelect(t *testing.T) {
	var p, v chan int
	go prodAndConuser(t, p, v)
	t.Log("stage 1")
	// go func() {
	// 	t.Logf("handle")
	// 	<-v
	// }()
	p <- 3
	time.Sleep(time.Second)
	t.Log("main end")
}
