#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void) {
    int N, i, a;
    int num[10000];
    while ( scanf ("%d", &N) ) {
        a = N-3;
        if(0 == N) {
            break;
        }
        for(i=0; i<N; i++) {
            scanf ("%d", num+i);
        }
        sort(num,num+N);
        while(1) {
            if ( num[a] + num[a+1] > num[a+2] ) {
                printf ("%d\n", num[a]+num[a+1]+num[a+2]);
                break;
            } else {
                a--;
            }
            if(a == -1) {
                printf ("0\n");
                break;
            }
        }
    }
    
    return 0;
}