package main

import (
	"time"

	"go.uber.org/zap"
)

func zapSugar() {
	logger, _ := zap.NewProduction()
	url := "www.baidu.com"
	defer logger.Sync() // flushes buffer, if any
	sugar := logger.Sugar()
	sugar.Infow("failed to fetch URL",
		// Structured context as loosely typed key-value pairs.
		"url", url,
		"attempt", 3,
		"backoff", time.Second,
	)
	sugar.Infof("Failed to fetch URL: %s", url)
}