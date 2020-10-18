package mytest

import (
	"context"
	"fmt"
	"testing"
	"time"
)

func f(ctx context.Context, name string) {
	for {
		select {
		case <-ctx.Done():
			fmt.Println(name, " out because ctx done")
			return
		default:
			fmt.Println(name, " sleep")
			time.Sleep(1 * time.Second)
		}
	}
}

func TestCancel(t *testing.T) {
	ctx, cancel := context.WithCancel(context.Background())
	for _, name := range []string{"f1", "f2", "f3"} {
		go f(ctx, name)
	}
	time.Sleep(3 * time.Second)
	fmt.Println("main wake up")
	cancel()
	time.Sleep(time.Second) // 等待goroutine打印
	fmt.Println("main exit")
}
