package channel_test

import (
	"log"
	"sync"
	"testing"
	"time"
)

func send(wg *sync.WaitGroup) (ch chan int) {
	ch = make(chan int)
	go func() {
		log.Println("send start")
		defer wg.Done()
		defer close(ch)
		for i := 0; i < 10; i++ {
			ch <- i
			log.Printf("send %d\n", i) // 这里阻塞
		}
		log.Println("send end")
	}()

	return
}

func recv(wg *sync.WaitGroup, ch chan int) {
	log.Println("recv start")
	defer wg.Done()
	for i := range ch {
		log.Printf("recv %d\n", i)
		time.Sleep(1 * time.Microsecond)
	}
	log.Println("recv end")
}

func TestSyncWaitGroup(t *testing.T) {
	var wg sync.WaitGroup

	wg.Add(1)
	ch := send(&wg)

	wg.Add(1)
	go recv(&wg, ch)

	wg.Wait()

	log.Println("main done after sleep")
}
