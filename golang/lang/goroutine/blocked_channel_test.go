package channel_test

import (
	"log"
	"testing"
	"time"
)

var (
	sleep1s, _ = time.ParseDuration("1s")
	sleep5s, _ = time.ParseDuration("5s")
	wait1ms, _ = time.ParseDuration("1ms")
)

func blockedSend() (ch chan int) {
	ch = make(chan int)

	go func() {
		defer close(ch)
		log.Println("send start")
		ch <- 0
		log.Println("send end")
	}()

	return
}

func blockedRecv(ch chan int) {
	log.Println("recv start")
	time.Sleep(wait1ms)
	i := <-ch
	log.Printf("recv %d\n", i)
}

func TestBlockedChannel(t *testing.T) {
	ch := blockedSend()
	go blockedRecv(ch)
	time.Sleep(sleep1s)
	log.Println("main done")
}
