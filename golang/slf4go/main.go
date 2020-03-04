package main

import (
	"os"

	// slog "github.com/phenix3443/slf4go"
	slog "github.com/go-eden/slf4go"
	sl "github.com/go-eden/slf4go-logrus"
	sz "github.com/phenix3443/slf4go-zap"
	"github.com/sirupsen/logrus"
	"go.uber.org/zap"
	"go.uber.org/zap/zapcore"
)

// func baseUsage() {
// 	slog.Debugf("debug time: %v", time.Now())
// 	slog.Warn("warn log")
// 	slog.Error("error log")
// }

// func namedLogger() {
// 	log1 := slog.GetLogger()
// 	log1.Debug("main logger")

// 	log2 := slog.NewLogger("testLogger")
// 	log2.Info("new logger")
// }

// func useFields() {
// 	log := slog.GetLogger()
// 	log.BindFields(slog.Fields{"age": 18})
// 	log.Info("with fields")
// }

// func useLevel() {
// 	log := slog.NewLogger("log")
// 	print(log.Level().String())
// }

// func useHook() {
// 	slog.RegisterHook(func(*slog.Log) {
// 		println("hello,hook")
// 	})
// 	log1 := slog.NewLogger("log1")
// 	log1.Info("use log1")
// 	log2 := slog.NewLogger("log2")
// 	log2.Info("use log2")
// }

func useLogrusDriver() {
	sl.Init()

	logrus.SetOutput(os.Stdout)
	logrus.SetFormatter(&logrus.JSONFormatter{})
	logrus.SetLevel(logrus.InfoLevel)

	slog.Debug("hello")
	slog.Info("what???")
	slog.Warnf("warnning: %v", "surrender")

	log := slog.GetLogger()
	log.BindFields(slog.Fields{"logger": "test"})
	log.Errorf("error!!! %v", 100)
}

func useZapDriver() {
	encoderConfig := zapcore.EncoderConfig{
		MessageKey:     "msg",
		LevelKey:       "level",
		TimeKey:        "time",
		NameKey:        "logger",
		CallerKey:      "caller",
		StacktraceKey:  "stacktrace",
		LineEnding:     zapcore.DefaultLineEnding,
		EncodeLevel:    zapcore.LowercaseLevelEncoder,
		EncodeTime:     zapcore.ISO8601TimeEncoder,
		EncodeDuration: zapcore.SecondsDurationEncoder,
		EncodeCaller:   zapcore.FullCallerEncoder,
	}
	atomLevel := zap.NewAtomicLevelAt(zap.DebugLevel)
	cfg := zap.Config{
		Level:             atomLevel,
		Development:       false,
		DisableCaller:     true,
		DisableStacktrace: true,
		Encoding:          "json",
		EncoderConfig:     encoderConfig,
		OutputPaths:       []string{"stdout", "/tmp/stdout"},
		ErrorOutputPaths:  []string{"stdout", "/tmp/zaperr"},
		InitialFields:     map[string]interface{}{"foo": "bar"},
	}

	sz.Init(&cfg)
	log1 := slog.NewLogger("test")
	log1.Debug("debug info")
	log1.Infof("info info,v=%d", 10)
	log1.WithFields(slog.Fields{"fav": "basketball"}).Warn("warn message")
}

func main() {
	// baseUsage()
	// namedLogger()
	// useFields()
	// useLevel()
	// useHook()
	// useLogrusDriver()
	useZapDriver()
}
