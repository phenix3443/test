package mytest

import (
	"sync"
	"testing"
)

//测试 select 使用
func TestSelect(t *testing.T) {
	var wg sync.WaitGroup

	wg.Add(1)
	in := func() chan int {
		in := make(chan int, 10)
		go func() {
			defer wg.Done()
			defer close(in) // 关闭输入
			for i := 0; i < 3; i++ {
				in <- i
			}
		}()
		return in
	}()

	wg.Add(1)
	out := func() chan int {
		out := make(chan int, 10)
		go func() {
			defer wg.Done()
			for c := range out {
				t.Logf("result: %d", c)
			}
		}()
		return out
	}()

	wg.Add(1)
	go func() {
		defer wg.Done()
		defer close(out)
		for v := range in {
			t.Logf("in: v=%d, handling", v)
			v++
			out <- v
		}
	}()

	wg.Wait()
}
