package main

import (
	"encoding/json"

	"go.uber.org/zap"
)

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
