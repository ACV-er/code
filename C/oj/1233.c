#include<stdio.h>

void show(int m, int f){
    char ch = 'A'+m-1;
    int i, mm;
    for(i=0; i<f; i++) {
        printf("%c", ch);
        ch--;
    }
    mm = (m-f)*2-1;
    for(i=0; i<mm; i++) {
        printf("%c", ch);
    }
    ch++;
    for(i=0; i<f; i++) {
        printf("%c", ch);
        ch++;
    }
    printf("\n");
    return;
}

int main(void) {
    int N, i, m;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &m);
        for(i=0; i<m; i++) {
            show(m, i);
        }
        for(i=m-2; i>-1; i--) {
            show(m, i);
        }
    }

    return 0;
}
