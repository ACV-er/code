#include<stdio.h>

int main(void) {
    __int64 a, b;
    int i;
    while( ~scanf("%I64d", &a) ) {
        a = a*a;
        if(a < 10000) {
            printf("%I64d\n", a);
        } else {
            b = a;
            i = 0;
            while( b != 0 ) {
                b = b/10;
                i++;
            }
            i = (i-3)/2;
            while(i--) {
                a/=10;
            }
            printf("%I64d\n", a%10000);
        }
    }

    return 0;
}
