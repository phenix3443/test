package test

import (
	"fmt"
	"testing"
	"time"
	"unsafe"
)

// func TestSliceSpace(t *testing.T) {
// 	var s1 []int
// 	s2 := []int{}
// 	fmt.Printf("s1=%p,s2=%p\n", s1, s2) // s1=0x0,s2=0x1268f58
// }

func TestSize(*testing.T) {
	// https://blog.csdn.net/qq_34777600/article/details/87195673
	var str string
	fmt.Println(unsafe.Sizeof(str))
	var s struct{}
	fmt.Println(unsafe.Sizeof(s))
	x := make([]struct{}, 0, 100)
	fmt.Printf("size=%d,len=%d,cap=%d\n", unsafe.Sizeof(x), len(x), cap(x))
}

// go test -run Add
func TestAddr(*testing.T) {
	s1 := struct{}{}
	s2 := struct{}{}
	fmt.Printf("&s1=%p,&s2=%p,&s1=&s2:%t\n", &s1, &s2, &s1 == &s2)
}

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
