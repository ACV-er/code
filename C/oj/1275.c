#include<stdio.h>
#include<string.h>

char week[7][6] = {"Mon", "Tue", "Wen", "Thur", "Fri", "Sat", "Sun"};

int answ[50][2];

int main(void) {
    int N, n, num, begin, end, da, i, j, k, flag, ans;
    char day[10];
    scanf("%d", &N);
    while(N--) {
        int a[5][11] = {0};
        ans = 0;
        scanf("%d %d", &n, &num);
        while(n--) {
            scanf("%s %d %d", day, &begin, &end);
            for(i=0; i<7; i++) {
                if( strcmp(day, week[i]) == 0) {
                    da = i;
                    break;
                }
            }
            if(da > 4) continue;
            for(i=begin-1; i<end; i++) {
                a[da][i] = 1;
            }
        }
        for(i=0; i<5; i++) {
            for(j=0; j<=11-num; j++) {
                flag = 0;
                for(k=j; k<j+num; k++) {
                    if(a[i][k] == 1 || ( j<4 && k>3 ) || (j<8 && k>7)) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    answ[ans][0] = i;
                    answ[ans++][1] = j;
                }
            }
        }
        printf("%d\n", ans);
        for(i=0; i<ans; i++) {
            printf("%s %d %d\n", week[ answ[i][0] ], answ[i][1]+1, answ[i][1]+num);
        }
    }

    return 0;
}
