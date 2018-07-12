#include<stdio.h>

int main(void) {
    int N, A, B, i;
    int a[3];
    scanf("%d", &N);
    while(N--) {
        for(i=0; i<3; i++) {
            scanf("%d", &a[i]);
            if(a[i] == 1) {
                a[i] = 7;
            }
        }
        if(a[0] == a[1] && a[1] == a[2]) {
            A = a[0]*10000;
        } else if(a[0] == a[1]) {
            A = a[0]*100 + a[2];
        } else if(a[0] == a[2]) {
            A = a[0]*100 + a[1];
        } else if(a[1] == a[2]) {
            A = a[0] + a[1]*100;
        } else {
            for(i=0; i<3; i++) {
                if(a[i] == 7) {
                    a[i] = 1;
                }
            }
            A= a[0] + a[1] + a[2];
        }
        for(i=0; i<3; i++) {
            scanf("%d", &a[i]);
            if(a[i] == 1) {
                a[i] = 7;
            }
        }        if(a[0] == a[1] && a[1] == a[2]) {
            B = a[0]*10000;
        } else if(a[0] == a[1]) {
            B = a[0]*100 + a[2];
        } else if(a[0] == a[2]) {
            B = a[0]*100 + a[1];
        } else if(a[1] == a[2]) {
            B = a[0] + a[1]*100;
        } else{
            for(i=0; i<3; i++) {
                if(a[i] == 7) {
                    a[i] = 1;
                }
            }
            B = a[0] + a[1] + a[2];
        }
        if(A > B) {
            printf("Alice\n");
        } else if(A < B) {
            printf("Bob\n");
        } else {
            printf("Draw\n");
        }

    }

    return 0;
}
