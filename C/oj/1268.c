#include<stdio.h>

struct node{
    int data;
    int line;
    int list;
} mm[101][101];

int m, n;

int main(void) {
    int N, i, j, check, ans;
    int max, min;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d", &m, &n);
        ans = 0;
        for(i=0; i<m; i++) {
            max = -1; min = 100000;
            for(j=0; j<n; j++) {
                scanf("%d", &mm[i][j].data);
                mm[i][j].list = mm[i][j].line = 0;
                if(max < mm[i][j].data) max = mm[i][j].data;
                if(min > mm[i][j].data) min = mm[i][j].data;
            }
            if(max != min) {
                for(j=0; j<n; j++) {
                    if(max == mm[i][j].data) mm[i][j].line = 1;
                    if(min == mm[i][j].data) mm[i][j].line = -1;
                }
            } else {
                for(j=0; j<n; j++) {
                    mm[i][j].line = 5;
                }
            }
        }
        for(j=0; j<n; j++) {
            max = -1; min = 100000;
            for(i=0; i<m; i++) {
                if(max < mm[i][j].data) max = mm[i][j].data;
                if(min > mm[i][j].data) min = mm[i][j].data;
            }
            if(max != min) {
                for(i=0; i<m; i++) {
                    if(max == mm[i][j].data && (mm[i][j].line == -1 || mm[i][j].line == 5) ) {
                        mm[i][j].list = 1;
                        ans++;
                    }
                    if(min == mm[i][j].data && mm[i][j].line > 0) {
                        mm[i][j].list = 1;
                        ans++;
                    }
                }
            } else {
                for(i=0; i<m; i++) {
                    if(mm[i][j].line != 0) {
                        mm[i][j].list = 1;
                        ans++;
                    }
                }
            }
        }
        if(ans != 0)
        printf("%d\n", ans);
        for(i=0; i<m; i++) {
            for(j=0; j<n; j++) {
                if(mm[i][j].list == 1) {
                    printf("%d %d %d\n", i, j, mm[i][j].data);
                }
            }
        }
        if(ans == 0) {
            printf("None\n");
        }
    }
}
