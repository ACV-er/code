#include<stdio.h>

int mm[10][10];
int a;


void show(void) {
	int n = a;
	for(int i=0;i<n-1;i++)
        for (int j=0;j<n;j++)
            printf("%d ",mm[i][j]);
    for (int j=0;j<n-1;j++)
        printf("%d ",mm[n-1][j]);
    printf("%d\n",mm[n-1][n-1]);
}


void move(char inst, int x, int y) {
    int n = a, i;
	int b[10];
    switch (inst)
    {
    case 'L':
        for (int i=0;i<n;i++)
            b[i]=mm[x][(i+y)%n];
        for (int i=0;i<n;i++)
            mm[x][i]=b[i];
        break;
    case 'R':
        for (int i=0;i<n;i++)
            b[i]=mm[x][(n+i-y)%n];
        for (int i=0;i<n;i++)
            mm[x][i]=b[i];
        break;
    case 'D':
        for (int i=0;i<n;i++)
            b[i]=mm[(i-y+n)%n][x];
        for (int i=0;i<n;i++)
            mm[i][x]=b[i];
        break;
    case 'U':
        for (int i=0;i<n;i++)
            b[i]=mm[(i+y)%n][x];
        for (int i=0;i<n;i++)
            mm[i][x]=b[i];
        break;
    }    

    return;
}

int main(void) {
    int N, b, x, y, i, j, m;
    char inst[10];
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d", &a, &b);
        m=1;
        for(i=0; i<a; i++) {
            for(j=0; j<a; j++) {
                mm[i][j] = m++;
            }
        }
        while(b--) {
            scanf("%s %d %d", inst, &x, &y);
            move(inst[0],x-1,y%a);
        }
        show();
    }

    return 0;
}

