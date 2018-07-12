#include<stdio.h>

int main(void) {
    int N, i, j, n, sum, flag;
    scanf("%d", &N);
    while(N--) {
        flag = 1;
        scanf("%d", &n);
        for(i=n-81; i<n; i++) {
            if(i<0) i=0;
            j = sum = i;
            while(j) {
                sum += j%10;
                j /= 10;
            }
            if(n == sum) {
                flag = 0;
                break;
            }
        }
        printf( (flag==1)?"Yes\n":"No\n" );
    }

    return 0;
}
