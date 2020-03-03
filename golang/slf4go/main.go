package main

import (
	"time"

	slog "github.com/go-eden/slf4go"
)

func baseUsage() {
	slog.Debugf("debug time: %v", time.Now())
	slog.Warn("warn log")
	slog.Error("error log")
}

func namedLogger() {
	log1 := slog.GetLogger()
	log1.Debug("main logger")

	log2 := slog.NewLogger("testLogger")
	log2.Info("new logger")
}

func useFields() {
	log := slog.GetLogger()
	log.BindFields(slog.Fields{"age": 18})
	log.Info("with fields")
}

func useLevel() {
	log := slog.NewLogger("log")
	print(log.Level().String())
}

func useHook() {
	slog.RegisterHook(func(*slog.Log) {
		println("hello,hook")
	})
	log1 := slog.NewLogger("log1")
	log1.Info("use log1")
	log2 := slog.NewLogger("log2")
	log2.Info("use log2")
}

func useDriver() {

}

func main() {
	// baseUsage()
	// namedLogger()
	// useFields()
	// useLevel()
	// useHook()
	useDriver()
}
