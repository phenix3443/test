package main

import "go.uber.org/zap"

func presetLogger() {
	el := zap.NewExample()
	defer el.Sync()
	el.Debug("zap example logger")

	dl, _ := zap.NewDevelopment()
	defer dl.Sync()
	dl.Debug("zap  develop logger")

	pl, _ := zap.NewProduction()
	defer pl.Sync()
	pl.Debug("zap production develop logger")
	pl.Info("zap production info logger")
}
