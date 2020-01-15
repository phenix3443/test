package main

import (
	"go.uber.org/zap"
)

func basicConfig() {
	// encoderConfig := zap.NewDevelopmentEncoderConfig()

	encoderConfig := zap.NewProductionEncoderConfig()

	// encoderConfig := zapcore.EncoderConfig{
	// 	MessageKey: "msg",
	// 	LevelKey:   "level",
	// 	TimeKey:    "time",
	// 	NameKey:    "logger",
	// 	// CallerKey:      "caller",
	// 	// StacktraceKey:  "stacktrace",
	// 	LineEnding:     zapcore.DefaultLineEnding,
	// 	EncodeLevel:    zapcore.LowercaseLevelEncoder, // 小写编码器
	// 	EncodeTime:     zapcore.ISO8601TimeEncoder,    // ISO8601 UTC 时间格式
	// 	EncodeDuration: zapcore.SecondsDurationEncoder,
	// 	EncodeCaller:   zapcore.FullCallerEncoder, // 全路径编码器
	// }
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

	logger, err := cfg.Build()
	if err != nil {
		panic(err)
	}
	defer logger.Sync()

	logger.Sugar().Debug("debug log show not diplay")

	logger.Sugar().Error("info log display")
}
