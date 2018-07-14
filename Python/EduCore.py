#!/usr/bin/python3
# -*- coding:utf8 -*-
# __author__ = "ACV-er"
import requests
#测试学号密码登录，但是貌似无法访问，postman也无法访问, 原因为该链接已废弃
CheckUrl = 'http://***.197.224.134:8083/jwgl/logincheck.jsp'
# CheckUrl = 'http://www.baidu.com'
data = {
    'username': '2017****0820',
    'password': '******',
    'identity': 'student',
    'role': 1
}
r = requests.post( CheckUrl, data=data )
print(r.text)