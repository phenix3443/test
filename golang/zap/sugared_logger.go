package main

import "go.uber.org/zap"

func zapSugaredLogger() {
	logger := zap.NewExample().Sugar()
	defer logger.Sync()

	logger.Debug("sugared logger debug message with println foramat")
	logger.Debugf("sugared logger debug message with printf format:%s", "foo")
	logger.Debugw("sugared logger debug message with k,v", "foo", "bar")
}

func zapLogger() {
	logger := zap.NewExample()
	defer logger.Sync()

	logger.Debug("zap logger debug info", zap.Int32("key", 32))
}
