package main

import (
	"encoding/json"

	"go.uber.org/zap"
)

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

func basicConfig() {
	rawJSON := []byte(`{
		"level": "debug",
		"encoding": "json",
		"outputPaths": ["stdout","/tmp/stdout"],
		"errorOutputPaths": ["stdout","/tmp/stderr"],
        "initialFields":{"foo":"bar"},
		"encoderConfig": {
			"messageKey": "message",
			"levelKey": "level",
			"levelEncoder": "lowercase"
		}
	}`)

	var cfg zap.Config
	if err := json.Unmarshal(rawJSON, &cfg); err != nil {
		panic(err)
	}

	logger, err := cfg.Build()
	if err != nil {
		panic(err)
	}
	defer logger.Sync()

	logger.Sugar().Debug("base configure debug log")

}

func basicConfig2() {
	var cfg zap.Config

	cfg.Level.SetLevel(zap.InfoLevel)
	cfg.OutputPaths = []string{"/tmp/stdout"}
	cfg.ErrorOutputPaths = []string{"/tmp/stderr"}
	cfg.Encoding = "json"
	cfg.EncoderConfig.MessageKey = "msg"
	cfg.EncoderConfig.LevelKey = "level"
	cfg.InitialFields = map[string]interface{}{"foo": "bar"}

	logger, err := cfg.Build()
	if err != nil {
		panic(err)
	}
	defer logger.Sync()

	logger.Sugar().Debug("debug log show not diplay")

	logger.Sugar().Error("info log display")
}

func advanceConfig() {

}

func childLogger() {
	logger := zap.NewExample().Sugar()
	defer logger.Sync()

	logger.Debug("main logger")

	cLogger := logger.With("child", true)
	cLogger.Debug("child logger")
}

func main() {
	// presetLogger()
	// zapSugaredLogger()
	// zapLogger()
	basicConfig()
	// childLogger()
}
