package main

import (
	"database/sql"
	"fmt"
	"log"

	_ "github.com/go-sql-driver/mysql"
)

func mysqlPing() {
	dsn := "root:toor@tcp(127.0.0.1:3306)/touch_manager"
	db, err := sql.Open("mysql", dsn)
	if err != nil {
		fmt.Println(err.Error())
	}

	if ok := db.Ping(); ok == nil {
		println("db still alive")
	}

}

func mysqlExec() {
	dsn := "root:toor@tcp(127.0.0.1:3306)/touch_manager"
	db, _ := sql.Open("mysql", dsn)

	res, err := db.Exec("replace into touch_rule values (?,?);", 1, "test")
	if err != nil {
		log.Fatal(err)
	}
	id, _ := res.LastInsertId()
	count, _ := res.RowsAffected()
	fmt.Println(id, count)
}

func mysqlQuery() {
	dsn := "root:toor@tcp(127.0.0.1:3306)/touch_manager"
	db, _ := sql.Open("mysql", dsn)

	rows, err := db.Query("select * from touch_rule;")

	defer rows.Close()

	if err != nil {
		log.Fatal(err)
	}

	for rows.Next() {
		var id uint32
		var content string
		err = rows.Scan(&id, &content)
		if err != nil {
			log.Fatal(err)
		}
		fmt.Println(id, content)
	}

	if err = rows.Err(); err != nil {
		log.Fatal(err)
	}

}

func mysqlQueryOne() {
	dsn := "root:toor@tcp(127.0.0.1:3306)/touch_manager"
	db, _ := sql.Open("mysql", dsn)
	var content string
	err := db.QueryRow("select content from touch_rule where rule_id = ?", 1).Scan(&content)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(content)
}

func mysqlNull() {
	dsn := "root:toor@tcp(127.0.0.1:3306)/touch_manager"
	db, _ := sql.Open("mysql", dsn)
	var content sql.NullString
	err := db.QueryRow("select content from touch_rule where rule_id = ?", 2).Scan(&content)
	if err != nil {
		log.Fatal(err)
	}
	if content.Valid {
		fmt.Println(content.String)
	} else {
		fmt.Println("null")
	}

}
