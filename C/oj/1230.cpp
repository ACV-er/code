#include"stdio.h"

int main(void) {
    int coun, delta, k;
    char res[10];
    while( ~scanf("%d %d %s", &coun, &delta, res) ) {
        if( (coun-delta)%2 != 0 || coun<delta || (delta==0 && res[0]!='D') || ( delta!=0 && res[0]=='D' ) ) {
            printf("Impossible\n");
            continue;
        }
        coun = (coun-delta)/2;
        if(res[0] == 'A') k=1;
        else k=0;
 //       cout << res <<endl;
        printf("%d:%d\n",coun+delta*k, coun+delta*(1-k) );
    }

    return 0;
}
