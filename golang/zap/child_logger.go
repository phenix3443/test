package main

import "go.uber.org/zap"

func childLogger() {
	logger := zap.NewExample().Sugar()
	defer logger.Sync()

	logger.Debug("main logger")

	cLogger := logger.With("child", true)
	cLogger.Debug("child logger")
}
