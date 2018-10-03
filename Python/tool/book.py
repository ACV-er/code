#!/usr/bin/python3
# -*- coding:utf-8 -*-

#悟空看书，可优化为 
#直接抛出目录页数个进程， 每一个进程去访问一个目录页面，抓取每一章的url，然后获取文章

import requests
import random
import re
from multiprocessing import Process, Manager, Lock
import json
import shutil
import os

#参数
bookid = 0 #bookid
Chapters = 0 #目录页数 章节数除50后向上取整

#下面代码用来形成代理
f = open("../proxy/result/accept", "r")
proxies = []
for line in f.readlines():
    proxies.append( { "http": "http://" + line[:-1], "https": "https://" + line[:-1], } )
f.close()
proxiesLen = len( proxies )

def getProxy():
    return proxies[ random.randint(0, proxiesLen) ]

url = "http://m.wukongks.com/book/read"
titleUrl = "http://m.wukongks.com/service/getChapterList"
titleParam = {
    "bookid": bookid,
    "_ajax": 1,
    "pg": 1,
    "sort": 0
}
head = {
    'User-Agent':'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36',
}
def getBook(num = 0):
    titleParam["pg"] = num
    while True: #这个地方要死循环， 要保证有网，有代理， 然后保证url存在， 不然会章节缺失
        try:
            r = requests.get(titleUrl, params=titleParam, headers=head, proxies=getProxy(), timeout=5)
            if( r.status_code == 200 ):
                break
            print( r.status_code )
        except:
            pass
    tem = json.loads( r.text )
    bookUrls = []
    for x in tem['content']:
        bookUrls.append("http://m.wukongks.com" + x['readUrl'])
    for url in bookUrls:
        while True:
            try:
                r = requests.get(url, proxies=getProxy(), headers = head, timeout=5)
                if( r.status_code == 200 ):
                    break
                print(url)
            except:
                pass
        mod = re.compile(r"class=\"title\">(.*?)<[\s\S]*?text\">\s?(.*?)\s?</div>")
        result = mod.findall(r.text)
        r.close()
        f = open("tmp/"+str(num)+".txt", "a+")
        for temp in result:
            tmp = temp[0].replace("\u3000", " ")
            f.write(tmp+"\n")
            tmp = temp[1].replace("<p>", "    ")
            tmp = tmp.replace("</p>", "\n")
            f.write(tmp)
        f.close()

if __name__ == "__main__":
    p = []
    try:
        shutil.rmtree("tmp")
    except:
        pass
    try:
        os.mkdir("tmp")
    except:
        print("创建临时文件夹tmp失败，请检查是否有写入权限")
        exit()
    resurlt = open("book.txt", "w+")
    for i in range(1, Chapters + 1):
        p.append( Process(target=getBook, args=(i, ) ) )
        p[-1].start()
    for i in range(1, Chapters + 1):
        p[i].join()
        f = open("tmp/"+str(i)+".txt", "r")
        tmp = f.read()
        resurlt.write(tmp)
        f.close()
    resurlt.close()
    shutil.rmtree("tmp")
    print( "All Done!\n" )
