package http_test

import (
	"fmt"
	"log"
	"net/http"
	"testing"
)

func sayHello(w http.ResponseWriter, req *http.Request) {
	fmt.Fprintln(w, "Hello,world!!")
}

// go test -run Server
// then run:

func TestServer(t *testing.T) {
	http.HandleFunc("/", sayHello)               // curl http://127.0.0.1:8080
	http.HandleFunc("/not-found", http.NotFound) // curl http://127.0.0.1:8080/not-found
	log.Fatal(http.ListenAndServe(":8080", nil))
}
