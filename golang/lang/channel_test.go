package lang

import (
	"fmt"
	"testing"
	"time"
)

func TestChannel(*testing.T) {
	strChan := make(chan string, 3)
	syncChan := make(chan struct{}, 1)
	mainChan := make(chan struct{}, 2)
	go func() {
		<-syncChan
		fmt.Println("[receiver] received a sync signal and wait a second....")
		time.Sleep(time.Second)
		for {
			if elem, ok := <-strChan; ok {
				fmt.Println("received:", elem)
			} else {
				break
			}
		}
		fmt.Println("[receiver] stoped")
		mainChan <- struct{}{}
	}()
	go func() {
		for i, elem := range []string{"a", "b", "c", "d"} {
			fmt.Println("[sender] sent:", elem)
			strChan <- elem
			if i%3 == 0 {
				syncChan <- struct{}{}
				fmt.Println("[sender] sent a sync signal,wait a second...")
				time.Sleep(time.Second)
			}
		}
		fmt.Println("[sender] wait 2 seconds...")
		time.Sleep(time.Second * 2)
		close(strChan)
		mainChan <- struct{}{}
	}()

	fmt.Println("[main] waiting...")
	<-mainChan
	<-mainChan
	fmt.Println("[main] stoped")
}
