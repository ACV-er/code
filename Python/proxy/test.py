#!/usr/bin/python
# -*- coding:utf8 -*-
import re
import requests
import pickle
import random
import time
import urllib
from multiprocessing import Process, Manager, Lock

# httpsProxy = []
# def setProxy():
#     file = open("good", "r")
#     httpProxy = []
#     i = 0
#     for line in file.readlines():
#         line = line[:-1]
#         proxies = {"http": "http://" + line, "https": "https://" + line,}
#         try:
#             r = requests.get("https://www.baidu.com", proxies = proxies, timeout = 2)
#             if r.text.find("www.baidu.com") != -1:
#                 httpProxy.append(proxies)
#         except:
#             pass
#     file.close()
#     file = open("cache/proxy", "wb+")
#     times = time.time()
#     pickle.dump(httpProxy, file, True)
#     file.close()
#     file = open("cache/proxyUpdataTime", "wb+")
#     pickle.dump(times, file, True)
#     file.close()

# def initProxy():
#     file = open("cache/proxy", "rb")
#     return pickle.load(file)
#     file.close()


# def getProxy():
#     return httpsProxy[ random.randint(0, len(httpsProxy)) ]
# setProxy()

# httpsProxy = initProxy()
# print( httpsProxy )
# print( getProxy() )

# import shutil
# import os
# try:
#     shutil.rmtree("result")
# except:
#     pass
# os.mkdir("result")
# file = open("result/proxy", "w+")
# file.write("123")
# file.close()
freeProxyUrl = "https://www.kuaidaili.com/free/intr/1"
# pattern = ".*/free/intr/1/$"
# if re.match(pattern, freeProxyUrl, flags=0) != None:
#     print("yes")
# print( urllib.urlparse(freeProxyUrl) )

# s['ww'] = {}
# s['ww']['all'] = 1
# s['ww']['all'] += 1

# print( s['www.89ip.cn']['all'] )

# print( urllib.parse.urlparse(freeProxyUrl).netloc )

# f = open("test.txt", "a+")
# d = 123
# x = { "all" : 0, "accept" : 0, "error" : 0 }
# nowtime = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
# str1 = "%-10s%-30sall:%-10daccept:%-10serror:%-10s" % (nowtime, d, x["all"], x["accept"], x["error"])
# # f.write("%10s\t %3d\t %6s\n"%("lwk", 56, 'female'))
# # f.close()
# print( str1 )

# def run(num, fileLock):
#     str1 = ""
#     for i in range(10):
#         str1 = str1 + str(num)
#     with fileLock:
#         for i in range(len(str1)):
#             f = open("test.txt", "a+")
#             f.write(str1[i])
#             f.close()
#         f = open("test.txt", "a+")
#         f.write("\n")
#         f.close()
# if __name__=='__main__':
#     p = []
#     fileLock = Lock()
#     for i in range(0,10):
#         p.append( Process(target=run, args=(i, fileLock)) )
#         p[i].start()
#     for i in range(0,10):
#         p[i].join()
#     print('Child process end.')

def run(lock, res = []):
    with lock:
        s.append("15")

manager = Manager()
s = manager.list()
lock = Lock()
p = []
for i in range(3):
    p.append( Process(target = run, args=(lock, s) ) )
for i in range(3):
    p[i].start()
for i in range(3):
    p[i].join()
print("最终")
print( s )