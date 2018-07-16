# -*- coding:utf-8 -*-
# author:phenix3443@gmail.com
# mysql connect 连接联系

import mysql.connector
config = {
    'user': 'root',
    'password': '',
    'host': '127.0.0.1',
    'pool_name': 'test',
    'pool_size': 32,
}

cnx = mysql.connector.connect(**config)
cur = cnx.cursor()
cur.execute("select version()")
print(cur.fetchone())
cur.close()
cnx.close()
