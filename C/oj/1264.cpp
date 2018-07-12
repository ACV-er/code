#include<stdio.h>
#include<string.h>
#include <algorithm>
#include<stdbool.h>

using namespace std;

char s[10020];//接收字符串 
int a[26];//存储每个字母最后出现的位置 

struct arr{
	char ch[30];
}m[10010]; //sort好像无法对二维数组操作，昨天试了好久，所以用结构体 ， 这里用来存储符合条件子串 

void cpy(int n, char str[], char str1[]) {
    int i;
    for(i=0; i<n; i++) {
        str[i] = str1[i];
    }
    str[i] = '\0';
    return;
}//从str1位置复制n个字符到str； 

void init(void) {
	for(int i=0; i<26; i++) {
		a[i] = -1;
	}

	return;
}//对a数组进行初始化 

bool cmp(struct arr a, struct arr b) {
    int h = strcmp(a.ch, b.ch);
    if( h < 0 ) {
        return true;
    } else {
        return false;
    }
}//为sort函数提供排序规则 

int main(void) {
    int coun, i, len, maxn, h;//coun为正在扫描的字串长度， maxn为已扫描过的字串的最大长度， h为符合条件字串计数器   
    while( scanf("%s", s) != EOF ) {
        len = strlen(s);
        init();
        h = maxn = coun = 0;
        for(i=0; i<len; i++) { // 扫描一遍; 
            if( a[s[i]-'a'] < (i-coun) ) {//i为当前位置， i-coun 为正在扫描子串的开始位置 
                a[s[i]-'a'] = i; //如果前一次该字符出现在子串开始位置之前， 则没有重复， 更新a数组； 
                coun++;//正在扫描子串长度加一 
            } else {
                if(coun > maxn) {
                	maxn = coun;
                    h = 0;
                    cpy(coun, m[h++].ch, (s+i-coun));
                } else if(coun == maxn) {
                    cpy(coun, m[h++].ch, (s+i-coun));
                }
                coun = i - a[s[i] -'a'];//coun更新为重复字符后一个到当前字符的距离 
                a[s[i]-'a'] = i;//更新a数组 
            }
        }
        if(coun > maxn) {
        	maxn = coun;
            h = 0;
            cpy(coun, m[h++].ch, (s+i-coun));
        } else if(coun == maxn) {
            cpy(coun, m[h++].ch, (s+i-coun));
        }//重复操作  防止最后出现coun>maxn却通过48行的判断而无法进入else 
        sort(m, m+h, cmp);
        printf("%d\n", maxn);
        printf("%s\n", m[0].ch);
        for(i=1; i<h; i++) {
            if( strcmp(m[i].ch, m[i-1].ch) ) {
                printf("%s\n", m[i].ch);
            }
        }
    }

    return 0;
}
