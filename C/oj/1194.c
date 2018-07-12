#include <stdio.h>

int res[1001][1001];

int main(void){
    int all, miss, a , j, i;
    long long int d, b[1001] = {1, 0};
     for(i=1; i<=1000; i++){
            res[i][i] = 1;
            res[0][i] = 1;
         }
        for(j=2; j<=1000; j++){
            for(i=1; i<=j; i++){
                res[i][j] = (res[i][j-1] + res[i-1][j-1]) % 1000000007;
            }
        }
        for(i=2; i<=1000; i++)
                b[i] = (i-1)*(b[i-1] + b[i-2]) % 1000000007;

    while(scanf("%d %d",&all,&miss),all||miss){
         d=res[miss][all]*b[miss]%1000000007;
                printf("%d\n",d);
    }
return 0;
}
