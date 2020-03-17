package channel_test

import (
	"log"
	"testing"
	"time"
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
	time.Sleep(time.Microsecond)
	i := <-ch
	log.Printf("recv %d\n", i)
}

// go test -run  BlockedChannel
func TestBlockedChannel(t *testing.T) {
	ch := blockedSend()
	go blockedRecv(ch)
	time.Sleep(time.Second)
	log.Println("main done")
}
