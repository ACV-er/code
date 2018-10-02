import re
import requests
import time
from multiprocessing import Process
import os
import shutil

def run(num):
    i = begin = num*250+10001
    end = begin+250
    while(i<end):
        f = open( './tmp/'+str(num)+'.txt', 'a+')
        strs = str(i)
        strs = strs.zfill(6)
        url = 'http://oeis.org/A'+strs
        try:
            r = requests.get(url)
            txt = r.text
            #print(txt)
            txt = re.sub(r'<wbr>', ', ', txt, count=0, flags=0)
            txt = re.sub(r'[^\x00-\x7f]', '<unkown>', txt, count=0, flags=0)
            title = re.findall(r'<td valign=top align=left>[\s]*([^\n]*)', txt)
            #<table cellspacing="0" cellpadding="2" cellborder="0">[\s]*<tr>[\s]*<td width="20">[\s]*<td width="710">[\s]*
            number = re.findall(r'<table cellspacing="0" cellpadding="2" cellborder="0">[\s]*<tr>[\s]*<td width="20">[\s]*<td width="710">[\s]*<tt>[\s]*([^<]*)</tt>', txt)
            #print(title[0])
            #print(number[0])
        except:
            f.close()
            continue
        f.write(title[0]+'\n')
        f.write(number[0]+'\n\n\n')
        f.close()
        i += 1


if __name__=='__main__':
    os.path.exists('./tmp') or os.mkdir('./tmp')
    time1 = ticks = time.time()
    print('Parent process %s.' % os.getpid())
    p = []
    for i in range(0,40):
        p.append( Process(target=run, args=(i,)) )
        p[i].start()
    for i in range(0,40):
        p[i].join()
    time2 = ticks = time.time()-time1
    print(time2)
    print('Child process end.')
    c = open('./result.txt', 'w+')
    
    text = ''
    for i in range(40):
        tmp = str(i)
        f = open('./tmp/' + tmp + '.txt', 'r')    
        text += f.read()   
        f.close()

    text = re.sub(r'&gt;', '>', text, count=0, flags=0)
    text = re.sub(r"&lt;", '<', text, count=0, flags=0)
    text = re.sub(r'<a[^>]*>', '', text, count=0, flags=0)
    text = re.sub(r'</a>', '', text, count=0, flags=0)

    c.write(text)
    c.close()
    shutil.rmtree('./tmp')
    print("success!")
