#include<stdio.h>
#include<stdbool.h>

bool num[5000000] = {false};
int nums[5000000] = {0,0,0,1,1};

void getprime(void);

int main(void) {
    int N, i, cnt=0, a, b;
    getprime();
    for(i=3; i<4999998; i+=2) {
        if(num[i]==0 && num[i+2]==0) {
            cnt++;
        }
        nums[i] = cnt;
        nums[i+1] = cnt;
    }

    scanf("%d", &N);
    while(N--) {
        cnt = 0;
        scanf("%d %d", &a, &b);
        printf ("%d\n", nums[b-2]-nums[a-1]);
    }

    return 0;
}

void getprime(void) {
    int i, j;
    for(i=2; i<3000; i++) {
        if(num[i] == false) {
            for(j=i*i; j<5000000; j += i) {
                num[j] = true;
            }
        }
    }
    return;
}
