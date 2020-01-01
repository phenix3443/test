package main

import (
	"encoding/json"

	"go.uber.org/zap"
)

func buildinLogger() {
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

func zapSugared() {
	logger := zap.NewExample().Sugar()
	defer logger.Sync()

	logger.Debug("debug message with println foramat")
	logger.Debugf("debug message with printf format:%s", "foo")
	logger.Debugw("debug message with k,v", "foo", "bar")
}

func zapLogger() {

}

func childLogger() {
	logger := zap.NewExample().Sugar()
	defer logger.Sync()

	logger.Debug("main logger")

	cLogger := logger.With("child", true)
	cLogger.Debug("child logger")
}

func basicConfig() {
	var cfg zap.Config

	// cfg.Level.SetLevel(zap.InfoLevel)
	// cfg.OutputPaths = []string{"/tmp/stdout"}
	// cfg.ErrorOutputPaths = []string{"/tmp/stderr"}
	// cfg.Encoding = "json"
	// cfg.EncoderConfig.MessageKey = "msg"
	// cfg.EncoderConfig.LevelKey = "level"
	// cfg.InitialFields = map[string]interface{}{"foo": "bar"}

	rawJSON := []byte(`{
		"level": "debug",
		"outputPaths": ["/tmp/stdout"],
		"errorOutputPaths": ["/tmp/stderr"],
		"encoding": "json",
		"encoderConfig": {
			"messageKey": "message",
			"levelKey": "level",
			"levelEncoder": "lowercase"
		}
	}`)

	if err := json.Unmarshal(rawJSON, &cfg); err != nil {
		panic(err)
	}

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

func main() {
	buildinLogger()

	// zapSugared()
	// childLogger()
	// basicConfig()
}
