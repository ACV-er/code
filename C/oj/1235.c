#include<stdio.h>
#include<string.h>

int main(void) {
    char a[10], b[10], c[20];
    int N, len, i, s, cnt;
    scanf("%d", &N);
    while(N--) {
        scanf("%s %s",a, b);
        len = strlen(a);
        s = len-2;
        len--;
        for(i=cnt=0; i<len; i++, s--) {
            c[cnt++] = a[i];
            c[cnt++] = b[s];
        }
        c[cnt++] = a[i];
        c[cnt] = '\0';
        printf("%s", c);
        printf("\n");
    }

    return 0;
}
