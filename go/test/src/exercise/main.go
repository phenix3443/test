package main

import (
	"context"
	"log"
	"time"

	xlsoa "gitlab.xunlei.cn/xlsoa/service"
	"google.golang.org/grpc"
)

func main() {
	env := xlsoa.NewEnvironment()
	ctx := xlsoa.NewClientContext(env, "xlsoa.example.greeter")
	conn, err := grpc.Dial(
		"xlsoa.example.greeter",
		grpc.WithInsecure(),
		grpc.WithDialer(ctx.GrpcDialer()),
		grpc.WithPerRPCCredentials(ctx.GrpcPerRPCCredentials()),
		grpc.WithUnaryInterceptor(ctx.GrpcUnaryClientInterceptor()),
		grpc.WithStreamInterceptor(ctx.GrpcStreamClientInterceptor()),
	)
	if err != nil {
		log.Fatal(err)
	}

	c := pb.NewGreeterClient(conn)
	for {
		r, err := c.SayHello(context.Background(), &pb.HelloRequest{Name: "world"})
		if err != nil {
			log.Printf("Could not greet: %v\n", err)
		} else {
			log.Printf("Greeting: %v\n", r.Message)
		}
		time.Sleep(1 * time.Second)
	}
	// req := &xlsoa_core.AuthorizeRequest{
	// 	GrantType: "urn:ietf:params:oauth:grant-type:jwt-bearer",
	// 	Assertion: s.jwtSign,
	// }
}
