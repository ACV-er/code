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
    int x = p + 1, left = p;
    for (; left <= r; left++) {
        if (a[left] < a[p]) {
            if (left != x) {
                swap(a + x, a + left);
            }
            x++;
        }
    }
    swap(a + p, a + x - 1);

    return x - 1; //返回的是下标
}

// 选择 a 数组中 p， r 之间 第 k 大的元素 (p, r 为数组下标，闭区间)
int select(int* a, int p, int r, int k)
{
    if (p == r) {
        return a[p];
    }
    int q = rand_select(a, p, r);
    // printf("%d ** ", q);
    // for (int i = 0; i < 10; i++) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    if (q == k - 1) {
        return a[q];
    } else if (q > k - 1) {
        return select(a, p, q - 1, k);
    } else {
        return select(a, q + 1, r, k);
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    int* a = rand_array(10);

    printf("%d\n", select(a, 0, 9, 5));

    return 0;
}