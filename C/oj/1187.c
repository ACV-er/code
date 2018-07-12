#include"stdio.h"

int main(void) {
    __int64 n, m, x, a, l;
    while(scanf("%I64d", &n) && n != 0) {
        m = n/3;
        a = n%3;
        x = m*(m-1)*(m-2)/6*(3-a) + m*(m-1)*(m+1)/6*a;
 //       printf("%I64d %I64d\n", m, a);
        if(a==2) l = m*(m+1)*(m+1);
        else if (a==1) l = m*m*(m+1);
        else l = m*m*m;
//        printf("%I64d %I64d\n", l, x);
        l = (x+l) % 1000000007;
        printf("%I64d\n", l);
    }

    return 0;
}
