#include<stdio.h>

int main(void) {
    int a, b, i, j, k, flag;
    char m[101][101];
    while( ~scanf("%d %d", &a, &b) ) {
        for(i=0; i<a; i++) {
            scanf("%s", m[i]);
        }
        getchar();
        for(i=0; i<a; i++) {
            for(j=0; j<b; j++) {
                flag = 1;
                for(k=0; k<a; k++) {
                    if(m[k][j] == m[i][j] && k!=i) {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                for(k=0; k<b; k++) {
                    if(m[i][k] == m[i][j] && k!=j) {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)printf("%c", m[i][j]);
            }
        }
        puts("");
    }

    return 0;
}
