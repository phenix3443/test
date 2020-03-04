package main

import (
	slog "github.com/go-eden/slf4go"
	// slog "github.com/phenix3443/slf4go"
	sz "github.com/phenix3443/slf4go-zap"
	"go.uber.org/zap"
	"go.uber.org/zap/zapcore"
)

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
	useZapDriver()
}
