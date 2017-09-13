package main

import (
	"os"

	"github.com/sirupsen/logrus"
	"github.com/zbindenren/logrus_mail"
)

func test_logrus() {
	logrus.SetOutput(os.Stdout)
	logrus.SetFormatter(&logrus.JSONFormatter{})
	// logrus.SetFormatter(&logrus.TextFormatter{})
	logrus.SetLevel(logrus.InfoLevel)
	logrus.Debug("debug log")
	logrus.Info("info log")
	logrus.Info(map[string]int{"age": 12})
}

func test_logger() {
	logger := &logrus.Logger{
		Out:       os.Stdout,
		Formatter: new(logrus.JSONFormatter),
		Level:     logrus.DebugLevel,
	}
	logger.Debug("debug log")
	logger.Info("info log")
	logger.Info(map[string]int{"age": 12})

}

func test_entry() {
	logger := &logrus.Logger{
		Out:       os.Stdout,
		Formatter: new(logrus.JSONFormatter),
		Level:     logrus.DebugLevel,
	}

	e := logrus.NewEntry(logger)
	e.WithFields(logrus.Fields{
		"name": "lsl",
		"age":  30,
	})

	e.Debug("debug log")
	e.Info("info log")
	e.Warn(e.Level)
}

func test_hook() {
	logger := logrus.New()
	//parameter"APPLICATION_NAME", "HOST", PORT, "FROM", "TO"
	//首先开启smtp服务，最后两个参数是smtp的用户名和密码
	hook, err := logrus_mail.NewMailAuthHook("APPLICATION_NAME", "HOST", PORT, "FROM", "TO", "USERNAME", "PASSWORD")

	if err != nil {
		logger.Error("init hook error")
	}
	logger.Hooks.Add(hook)

	e := logger.WithFields(logrus.Fields{
		"content": "test logrus hook",
	})
	//设置时间戳和message
	e.Error("这是一个hook发来的邮件")

	//使用Fire发送,包含时间戳，message
	hook.Fire(e)

}
func main() {
	// test_logrus()
	// test_logger()
	// test_entry()
	test_hook()

}
