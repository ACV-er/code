#include<stdio.h>

int a[15][15];

int m, n;

char inst[15];

void show(void) {
    int i, j;
    for(i=0; i<m; i++) {
        for(j=0; j<n-1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][j]);
    }
    printf("\n");

    return;
}

void exline(int x, int y) {
    int i, t;
    for(i=0; i<n; i++) {
        t = a[x][i];
        a[x][i] = a[y][i];
        a[y][i] = t;
    }

    return;
}

void exlist(int x, int y) {
    int i, t;
    for(i=0; i<m; i++) {
        t = a[i][x];
        a[i][x] = a[i][y];
        a[i][y] = t;
    }

    return;
}

void change() {
    int i, l, t;
    if(inst[0] == 'F') {
        if(inst[1] == 'R') {
            l = m/2;
            for(i=0; i<l; i++) {
                exline(i, m-1-i);
            }
        } else {
            l = n/2;
            for(i=0; i<l; i++) {
                exlist(i, n-1-i);
            }
        }
    } else if(inst[0] == 'T') {
    	if(n>m)
	        for(i=0; i<m; i++) {
	            for(l=i; l<n; l++) {
	                t = a[i][l];
	                a[i][l] = a[l][i];
	                a[l][i] = t;
	            }
	        }
        else
        	for(l=0; l<n; l++) {
	            for(i=l; i<m; i++) {
	                t = a[i][l];
	                a[i][l] = a[l][i];
	                a[l][i] = t;
	            }
	        }
        t = m;
        m = n;
        n = t;
    }

    return;
}

void init(void) {
    int i, j, cnt = 1;
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            a[i][j] = cnt++;
        }
    }

    return;
}

int main(void) {
    int x, y;
    while( ~scanf("%s", inst) ) {
        if(inst[0] == 'S') {
            scanf("%d %d", &x, &y);
            x--; y--;
            if(inst[1] == 'R') {
                exline(x, y);
            } else {
                exlist(x, y);
            }
        } else if(inst[0] == 'I') {
            scanf("%d %d", &m, &n);
            init();
        } else if(inst[0] == 'P') {
            show();
        } else {
            change();
        }
    }

    return 0;
}
