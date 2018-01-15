package main

import (
	"fmt"
	"net/http"
	"time"
)

func main() {
	// client := redis.NewClient(&redis.Options{
	// 	Addr: "localhost:6379",
	// })

	// if val, err := client.HGet("foo", "zoo").Result(); err != nil {
	// 	if err == redis.Nil {
	// 		fmt.Printf("key not exist")
	// 	} else {
	// 		fmt.Printf("%v", err)
	// 	}

	// } else {
	// 	fmt.Printf("%v", val)
	// }

	// keys := []int{3, 2, 8, 1}
	// sort.Sort(sort.Reverse(sort.IntSlice(keys)))
	// fmt.Println(keys)
	http.HandleFunc("/", IndexHandle)
	http.HandleFunc("/static", StaticHandle)
	http.ListenAndServe("127.0.0.1:8000", nil)
	// if delta, err := time.ParseDuration("-5m"); err == nil {
	// 	fmt.Println(delta.Seconds())
	// }

}
func StaticHandle(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()
	query := r.URL.Query()
	content := "hello,world"
	if interval, ok := query["interval"]; ok {
		v, err := time.ParseDuration(interval[0])
		if err != nil {
			content = Usage()
		}
		ts := time.Now().Add(v).Format("200601021504")
		content = fmt.Sprintf("%s", ts)
	}

	fmt.Fprintln(w, content)
}
func IndexHandle(w http.ResponseWriter, r *http.Request) {
	content := Usage()
	fmt.Fprintln(w, content)
}

func Usage() (s string) {
	s = "usage:\n\t/static?interval=1m|30s"
	return
}
