package main

import (
	"fmt"
	"io"
	"net/http"
)

// hello world, the web server
func HelloServer(w http.ResponseWriter, req *http.Request) {
	io.WriteString(w, "hello, world!\n")
}

func main() {
	http.HandleFunc("/hello", HelloServer)
	err := http.ListenAndServe(":12345", nil)
	fmt.Printf(":%v:", err)
	if err != nil {
		fmt.Println("error")
		return
	}
}
