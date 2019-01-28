#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* rand_array(int len)
{
    if (len < 1) {
        return NULL;
    }
    int i, t, tmp;
    int* rand_array = (int*)malloc(sizeof(int) * len);
    for (i = 0; i < len; i++) {
        rand_array[i] = i;
    }
    for (i = 0; i < len; i++) {
        tmp = rand() % len;
        t = rand_array[i];
        rand_array[i] = rand_array[tmp];
        rand_array[tmp] = t;
    }

    return rand_array;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int rand_select(int* a, int p, int r)
{
    int x = p + 1, left = p, right = r;
    for (; left < right; left++) {
        if (a[left] < a[p]) {
            while(a[x] <= a[p] && x < r) {
                x++;
            }
            if(  )
        }
    }
}

// 选择 a 数组中 p， r 之间 第 k 大的元素 (p, r 为数组下标，闭区间)
int select(int* a, int p, int r, int k)
{
    if (p == r) {
        return a[p];
    }
    int q = rand_select(a, p, r);
    if (q == k) {
        return a[q];
    } else if (q > k) {
        return select(int* a, int p, int q - 1, int k)
    } else {
        return select(int* a, int q + 1, int r, int k - q)
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    int* a = rand_array(10);

    return 0;
}