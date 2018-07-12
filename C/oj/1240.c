#include<stdio.h>

int main(void) {
    int now, coun;
    while( scanf("%d", &now) && now) {
        if(now == 1) {
        	coun = 0;
        } else if(now == 2) {
        	coun = 1;
        } else {
        	coun = now*3 - 5;
        }
        printf("%d\n", coun);
    }

    return 0;
}
