#!/usr/bin/python3
# -*- coding:utf-8 -*-
import requests
import re
from multiprocessing import Process, Manager, Lock
import random
import pickle
import shutil
import os
import time
from urllib import parse
class Proxy:
    allProxy = [] #保存获取的代理，去重
    allUrl = [] #保存爬取过的网页，去重
    httpsProxy = [] #保存代理,此代理为以前获取过的代理，用来爬取免费代理
    httpsProxyLen = 0
    manager = Manager()
    proxyInfo = manager.dict({}) #保存每个网站的代理的大概信息
    lock = Lock()
    fileLock = Lock()

    def __init__(self, updateProxy = True):
        #初始化代理
        try:
            f = open("cache/proxyUpdataTime", "rb")
            proxyUpdataTime = pickle.load(f) #获取上一次设置代理的时间
            f.close()
            nowTime = time.time()
            if nowTime - proxyUpdataTime > 86400: #86400为24小时的秒数
                self.setProxy()
        except:
            print("没找到缓存文件proxyUpdataTime中的时间缓存,请尝试手动调用setProxy方法")
            self.log("没找到缓存文件proxyUpdataTime中的时间缓存")
        try:
            f = open("cache/proxy", "rb")
            self.httpsProxy = pickle.load(f)
            f.close()
            self.httpsProxyLen = len( self.httpsProxy )
        except:
            print("没找到缓存文件proxy中的代理缓存,请尝试手动调用setProxy方法")
            self.log("没找到缓存文件proxy中的代理缓存")
        #初始化结果文件
        if updateProxy:
            try:
                shutil.rmtree("result")
            except:
                pass
            os.mkdir("result")

        #使用免费代理页面url，网址写在 目录下freeProxyUrl文件
        #网址的格式为****/后缀 如  www.66ip.cn/1.html
            f = open("freeProxyUrl", "r")
            for freeProxyUrl in f.readlines():
                freeProxyUrl = freeProxyUrl[:-1]
                self.getPageProxy( freeProxyUrl )
            f.close()
        #写log,方便查看每个站点的代理质量
            f = open("log", "a+")
            print("信息写入log")
            for d,x in self.proxyInfo.items():
                self.log( "%-30sall:%-10daccept:%-10serror:%s\n" % (d, x["all"], x["accept"], x["error"] ))
            f.close()
            print("完成！")
        #单独某个页面
        # url = "http://www.66ip.cn/1.html"
        # getPageProxy(url)

    '''
        proxys     代理列表
        level　　　 过滤等级
        isSave　　　是否保存
        number　　　多进程时需要填的参数,负责标记对应进程
        result　　　多进程时储存数据
        url　　　   多进程存储url
        lock　　　  进程锁,锁proxyInfo
        proxyInfo  保存每个网站的代理的大概信息
    '''

    def proxyCheck(self, proxys=[], level = "accept", isSave=True, number=-1, url="", lock=Lock(), fileLock=Lock(),proxyInfo = {}):
        #代理等级过滤，响应时间为判定依据
        levels = {
            "accept" : 5,
            "good"   : 3,
            "fast"   : 1.5,
            "faster" : 0.5,
        }
        timeOut = levels[level]
        # jwxtUrl = "http://jwxt.xtu.edu.cn/jsxsd"
        # xxmhUrl = "http://202.197.224.171/zfca/login"
        baiduUrl = "http://www.baidu.com"

        acceptProxys = []
        count  = len(proxys)
        accept = 0
        error  = 0

        #测试代理是否可用
        for proxy in proxys:
            try:
                proxies = { "http": "http://" + proxy, "https": "https://" + proxy, }
                baiduCheck = requests.get(baiduUrl, proxies=proxies, timeout = timeOut)

                #判断教务系统及信息门户，意义不大，只判断一个即可
                # xxmhCheck = requests.get(xxmhUrl, proxies=proxies, timeout = 2)
                # if( (jwxtCheck.status_code == 200) and (xxmhCheck.status_code == 200) ):

                #判断是否真的获取到了教务 判断两次，把不稳定的也爬取过来

                #鉴于教务系统访问率，将验证方式改为访问百度,只验证一次
                if( (baiduCheck.text).find("www.baidu.com") != -1 ):
                    # print("success  " + str(jwxtCheck.elapsed.microseconds/1000) + "ms")
                    acceptProxys.append(proxy)
                    accept += 1
                else:
                    error += 1
            except:
                error += 1
        # print( "all: " + str(count) + " accept: " + str(accept) + " error: " + str(error) )
        if url != "":
            lock.acquire()
            # try:
            if url not in proxyInfo:
                proxyInfo[url] = { "all" : count, "accept" : accept, "error" : error }
            else:
                temp = proxyInfo[url]
                temp["all"] += count
                temp["accept"] += accept
                temp["error"] += error

                proxyInfo[url] = temp
            # except:
            #     pass
            lock.release()
        if( isSave ):
            self.saveProxy(acceptProxys, level)
        elif number != -1:
            with fileLock:
                self.saveProxy(acceptProxys, level)
        else:
            pass

    #传入页面url，自动获取页面内的代理
    def getPageProxy(self, freeProxyUrl):
        pages = 0
        isContinue = True #进去的时候默认进行爬取
        MAX = 5 #设置每个进程处理的代理的个数，越小越快，但是进程会越多
        p = [] #存储进程
        num = 0 #标记进程

        while isContinue and pages<50:
            pages += 1
            isContinue = False #返会False代表该页面没有新的代理，和以前获取的东西完全重复
            self.allUrl.append(freeProxyUrl) #该网站已被获取，保存
            print(freeProxyUrl)
            host = parse.urlparse(freeProxyUrl).netloc
            proxys = []
            # blank = re.compile(r"\s")
            #下面是原来的正则, 需要去除所有空白符
            # mod = re.compile(r"(\d{2,3}\.\d{2,3}\.\d+\.\d+)(?:.*?>\s*?|:)(\d{2,6})")

            mod = re.compile(r"(\d{2,3}\.\d{2,3}\.\d+\.\d+)[\s\S]*?(?:>\s*?|:)(\d{2,6})")
            #简单防反爬
            heard = {
                'User-Agent':'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36',
                'Host': host,
                'Referer': "https://www.baidu.com"
            }
            print("获取网页信息")
            for i in range(10):
                try:
                    r = requests.get(freeProxyUrl, headers = heard, proxies = self.getProxy(), timeout = 10)
                    if( r.status_code == 200 ):
                        break
                    print("第%d次尝试失败" % (i+1))
                except:
                    print("第%d次尝试失败" % (i+1))
                    continue
            try:
                result = r.text
                print("获取网页信息完毕")
            except:
                print("获取网页信息失败")
                self.log( "Message:%s访问失败" % freeProxyUrl )
                result = ""
            # 取出空白符，改进正则之后不太需要了,但是有可能正则跑的很慢
            # blank = re.compile(r"\s")
            # result = blank.sub("", result)

            #把获取到的东西组成 xx.xx.xx.xx:xxxx ip:port  的形式，并判断重复
            results = mod.findall(result)
            for res in results:
                proxy = res[0] + ":" + res[1]
                if proxy in self.allProxy:
                    continue
                else:
                    self.allProxy.append(proxy)
                    isContinue = True
                    proxys.append(proxy)
            #检查获取到的代理的可用性,此处使用默认等级accept
            #如果一次获取数量大于MAX则分批加入多进程
            begin = 0
            end = len(proxys)
            print("该页面提取到" + str(end) + "个代理")

            while begin != end:
                if end-begin > MAX:
                    p.append( Process(target=self.proxyCheck, args=(proxys[begin:begin+MAX], "accept", False, num, host, self.lock, self.fileLock,self.proxyInfo) ) )
                    begin += MAX
                else:
                    p.append( Process(target=self.proxyCheck, args=(proxys[begin:end], "accept", False, num, host, self.lock, self.fileLock, self.proxyInfo) ) )
                    begin = end
                p[num].start()

                num += 1

            proxys.clear()
                
            #此处获取下一页
            print("分析下一页链接")
            mod = re.compile(r"href=\"([^>]*)?\"[^>]*?>[^>]*?(?:下一|&raquo)")
            m = mod.search(result)
            try:
                if m != None:
                    freeProxyUrl = self.getNextPage( freeProxyUrl, m.group(1) )
                else:
                    mod = re.compile(r"href=\"\.?([^\"]*)") #匹配当前页面中所有链接，找出可能是跳转到当前页面的那一个，然后取出紧接着的下一个标签
                    result = mod.findall(result)
                    res = iter(result) #创建迭代器
                    #匹配出可能跳转到当前页面的链接
                    while True:
                        x = res.__next__()
                        if len(x) > 5:
                            pattern = ".*" + x + "$"
                            if re.match(pattern, freeProxyUrl, flags=0) != None:
                                break
                    freeProxyUrl = self.getNextPage( freeProxyUrl, res.__next__() )
                if freeProxyUrl in self.allUrl: #如果这个url已经被访问过则不继续
                    isContinue = False
            except:
                isContinue = False #如果提取不到下一页则不继续
            print("分析完毕")
        print("等待代理验证完成")
        for i in range(0, num):
            p[i].join()
        print("代理验证完成")

    def getNextPage(self, url = "", params = ""):
        if( params.find(url[:-8]) != -1 ): #判断params是链接还是参数或者路径
            return params
        else:
            index=url.find(params[0:4]) #如果匹配到了url中的一部分，那么拼接起来就可以了
            if index != -1:
                url = url[0:index] + params
            else:
                m = re.match(r"^.*?(\w.*)", params)
                params = m.group(1)
                m = re.match( "(.*/).+", url )
                url = m.group(1) + params

            return url

    #保存代理列表中的到指定文件
    def saveProxy(self, proxys = [], file = ""):
        file = "result/" + file
        f = open(file, "a+")
        for proxy in proxys:
            f.write(proxy + "\n")
        f.close()

    def errorProxy(self, proxy=""):
        f = open("error", "a+")
        f.write(proxy + "\n")
        f.close()

    def setProxy(self):
        try:
            print("初始化代理")
            self.getFast("good")
            f = open("result/good", "r")
            httpsProxy = []
            accept = 0
            for line in f.readlines():
                line = line[:-1]
                proxies = {"http": "http://" + line, "https": "https://" + line,}
                try:
                    r = requests.get("https://www.baidu.com", proxies = proxies, timeout = 1)
                    if r.text.find("www.baidu.com") != -1:
                        httpsProxy.append(proxies)
                        accept += 1
                except:
                    pass
            f.close()
            f = open("cache/proxy", "wb+")
            pickle.dump(httpsProxy, f)
            f.close()
            print("初始化完毕")
            f = open("cache/proxyUpdataTime", "wb+")
            pickle.dump(time.time(), f)
            f.close()
            self.log("Message:初始化代理成功%d个" % accept)
        except:
            self.log("Message:初始化代理失败，请检查目录下是否有result/accept文件")

    def getProxy(self):
        try:
            return self.httpsProxy[ random.randint(0, self.httpsProxyLen) ]
        except:
            return ""

    def getFast(self, mode = "fast"):
        try:
            MAX = 5
            f = open("result/accept", "r")
            proxys = []
            for freeProxyUrl in f.readlines():
                freeProxyUrl = freeProxyUrl[:-1]
                proxys.append(freeProxyUrl)
            f.close()

            #从getProxy中复制过来的
            num = 0
            p = []
            begin = 0
            end = len(proxys)
            while begin != end:
                if end-begin > MAX:
                    p.append( Process(target=self.proxyCheck, args=(proxys[begin:begin+MAX], mode, False, num, "", self.lock, self.fileLock) ) )
                    begin += MAX
                else:
                    p.append( Process(target=self.proxyCheck, args=(proxys[begin:end], mode, False, num, "", self.lock, self.fileLock) ) )
                    begin = end
                p[num].start()

                num += 1
            proxys.clear()
            print("等待代理验证完成")
            for i in range(0, num):
                p[i].join()
            print("代理验证完成")
        except:
            pass

    def log(self, logMessage= ""):
        nowtime = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
        f = open("log", "a+")
        f.write( "%-30s%s" % (nowtime,logMessage) )
        f.close()

proxy = Proxy(False)
proxy.setProxy()
 