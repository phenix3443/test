package main

import (
	"database/sql"
	"fmt"

	_ "github.com/go-sql-driver/mysql"
)

func mySQLPing() {
	dsn := "root:toor@tcp(127.0.0.1:3306)/touch_manager"
	db, err := sql.Open("mysql", dsn)
	if err != nil {
		fmt.Println(err.Error())
	}
	ok := db.Ping()
	if ok == nil {
		println("db still alive")
	}
}
