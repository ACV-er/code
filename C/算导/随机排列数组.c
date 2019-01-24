#include<stdio.h>
#include<stdlib.h>
#include<time.h>



/**
len 返回数组的长度

返回值 指向随机动态数组的指针
*/
int * rand_array(int len) {
    int i, t, tmp;
    int* rand_array = (int *)malloc(sizeof(int) * len);
    for(i=0; i<len; i++) {
        rand_array[i] = i;
    }
    for(i=0; i<len; i++) {
        tmp = rand() % len;
        t = rand_array[i];
        rand_array[i] = rand_array[tmp];
        rand_array[tmp] = t;
    }

    return rand_array;
}

int main(void) {
    srand((unsigned)time(NULL));
    int * a = rand_array(10);
    for(int i=0; i<10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}