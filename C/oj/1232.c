#include<stdio.h>

int gcd(int a, int b) {
    int c;
    while(b!=0) {
        c = a%b;
        a = b;
        b = c;
    }

    return a;
}

int main(void) {
    int N, a, b, sum, t;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d", &a, &b);
        if(a==0 || b==0) {
            printf("0\n");
            continue;
        }
        sum = a+b;

        sum = sum*(sum-1)/2;
        a = a*b;
        if(sum == a) {
            printf("1\n");
            continue;
        }
        t = gcd(sum, a);
        printf("%d/%d\n",a/t,sum/t);

    }

    return 0;
}
