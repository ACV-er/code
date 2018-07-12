#include<stdio.h>
#include<algorithm>
#include<stdbool.h>

typedef struct ele{
    int line;
    int listt;
    int value;
    int weight;
}Ele, *pEle;

bool cmp(Ele a, Ele b) {
    return (a.weight < b.weight);
}

int main(void) {
    int N;
    int n, i;
    Ele mm[10000];
    scanf("%d", &N);
    while(N--) {
        scanf("%*d %*d %d", &n);
        for(i=0; i<n; i++) {
            scanf("%d %d %d", &(mm+i)->listt, &(mm+i)->line, &(mm+i)->value);
            (mm+i)->weight = 1000*(mm+i)->line + (mm+i)->listt;
        }
        std::sort(mm,mm+n,cmp);
        for(i=0; i<n; i++) {
            printf("%d %d %d\n", (mm+i)->line, (mm+i)->listt, (mm+i)->value);
        }
        printf("\n");
    }

    return 0;
}
