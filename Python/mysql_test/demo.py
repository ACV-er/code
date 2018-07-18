# !/usr/bin/python3
# -*- coding:utf8 -*-
# __author__ = "ACV-er"
import pymysql
import json

if __name__ == "__main__":
    conn = pymysql.connect(host='127.0.0.1', user='root', passwd="*******009411", db='demo')
    cur = conn.cursor()
    cur.execute("SELECT * FROM demo")
    # print( cur.connection.__dict__ )
    data = ( cur.connection.__dict__ )
    print( type(cur.connection.cursorclass) )
    cur.close()
    conn.close()