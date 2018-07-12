#include<stdio.h>

int main(void) {
    int sum, check, unknow, i;
    char ch[11];
    while(scanf("%s", ch) != EOF) {
        sum = 0;
        for(i=0; i<10; i++) {
            if(ch[i] == '?') {
                unknow = i;
            } else {
                if(ch[i] == 'X') sum += 10;
                else
                sum += (10-i)*(ch[i] - '0');
            }
        }
        if(unknow == 9) {
            for(i=0; i<11; i++) {
                if( (sum+i)%11 == 0) {
                    ch[9] = i + '0';
                }
            }
            if(ch[9] >'9') {
                ch[9] = 'X';
            }
        } else {
            if(ch[9] == 'X') {
                ch[9] = 10;
            } else {
                ch[9] -= '0';
            }
            for(i=0; i<10; i++) {
                if( (sum + i*(10-unknow))%11 == 0 ) {
                    ch[unknow] = i+'0';
                    break;
                }
            }
            if(ch[9] == 10) {
                ch[9] = 'X';
            } else {
                ch[9] += '0';
            }
        }

        printf("%s\n", ch);;
    }


    return 0;
}
