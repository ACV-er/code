#include<stdio.h>

int main(void) {
    int level, i, n, dire, flag, coun;
    int test[1020];
    while(scanf("%d", &n) != EOF) {
        for(i=0; i<n; i++) {
            scanf("%d", &test[i]);
        }
        coun = level = 0;
        while(1) {
            for(i=0; i<n; i++) {
                if(level >= test[i]) {
                    level++;
                    test[i] = 10000;
                }
            }
            if(n != level) {
                coun++;
            } else {
                break;
            }
            for(i=n-1; i>-1; i--) {
                if(level >= test[i]) {
                    level++;
                    test[i] = 10000;
                }
            }
            if(n != level) {
                coun++;
            } else {
                break;
            }
        }
        printf("%d\n", coun);
    }

    return 0;
}
