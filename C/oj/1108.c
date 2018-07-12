#include<stdio.h>
#include<string.h>

int pows(int a, int b) {
    int c = 1;
    while(b--) {
        c *= a;
    }

    return c;
}

int main(void) {
    int N, i, A, B, radi, len;
    char a[35];
    scanf("%d", &N);
    while(N--) {
        A = B = 0;
        scanf("%s %d", a, &radi);
        len = strlen(a);
        if(a[0] == '-') {
            i = 1;
        } else {
            i = 0;
        }
        for(; i<len; i++) {
            if(a[i]>='0' && a[i]<='9') {
                a[i] -= '0';
                A += pows(radi, len-i-1) * a[i];
            }
            if(a[i]>='A' && a[i]<='Z') {
                a[i] -= 'A'-10;
                A += pows(radi, len-i-1) * a[i];
            }
            if(a[i]>='a' && a[i]<='z') {
                a[i] -= 'a'-36;
                A += pows(radi, len-i-1) * a[i];
            }
        }
        if(a[0] == '-') A = -A;
        scanf("%s %d", a, &radi);
        len = strlen(a);
        if(a[0] == '-') {
            i = 1;
        } else {
            i = 0;
        }
        for(; i<len; i++) {
            if(a[i]>='0' && a[i]<='9') {
                a[i] -= '0';
                B += pows(radi, len-i-1) * a[i];
            }
            if(a[i]>='A' && a[i]<='Z') {
                a[i] -= 'A'-10;
                B += pows(radi, len-i-1) * a[i];
            }
            if(a[i]>='a' && a[i]<='z') {
                a[i] -= 'a'-36;
                B += pows(radi, len-i-1) * a[i];
            }
        }
        if(a[0] == '-') B = -B;
        printf("%d\n", A+B);

    }

    return 0;
}
