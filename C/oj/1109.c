#include<stdio.h>

int main(void) {
    int N, nn, i, j, k;
    char m[250];
    char n[250];
    scanf("%d", &N);
    for(k=1; k<=N; k++) {
        scanf("%d", &nn);
        scanf("%s", m);
        for(i=1; i<nn; i++) {
            scanf("%s", n);
            for(j=0; m[j] != '\0'; j++) {
                if(m[j] != n[j]) {
                    m[j] = '\0';
                }
            }
        }
        printf("Case %d: %s\n", k, m);
    }

    return 0;
}
