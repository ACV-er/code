#include"stdio.h"

int main(void) {
    int N, m, n, i;
    scanf("%d", &N);
    while(N--) {
        int flag = 1;
        scanf("%d %d", &n, &m);
        for(i=0; i<=n; i++, n--) {
            if(n*i == m) {
                printf("%d %d\n", i, n);
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            printf("None\n");
        }
    }

    return 0;
}
