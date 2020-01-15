package main

import (
	"time"

	"go.uber.org/zap"
)

func atomLevelTest() {
	encoderConfig := zap.NewDevelopmentEncoderConfig()
	atomLevel := zap.NewAtomicLevelAt(zap.DebugLevel)

	cfg := zap.Config{
		Level:             atomLevel,
		Development:       false,
		DisableCaller:     true,
		DisableStacktrace: true,
		Encoding:          "json",
		EncoderConfig:     encoderConfig,
	}

	logger, err := cfg.Build()
	if err != nil {
		panic(err)
	}

	defer logger.Sync()

	for true {
		t, _ := time.ParseDuration("1s")
		time.Sleep(t)

		logger.Sugar().Debug("debug log show not diplay")

		logger.Sugar().Error("info log display")
	}
}
