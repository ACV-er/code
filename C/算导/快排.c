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

// 快排1
// void quick_sort(int* a, int len)
// {
//     int tmp = a[0], left = 0, right = len - 1;
//     if (len < 2)
//         return;
//     while (left < right) {
//         while (left < right && a[right] > tmp)
//             right--;
//         while (left < right && a[left] <= tmp)
//             left++;
//         swap((a + left), (a + right));
//     }
//     swap(a, a + left);
//     quick_sort(a, left);
//     left++;
//     quick_sort(a + left, len - left);

//     return;
// }


// 快排2
void quick_sort(int* a, int len)
{
    int tmp = a[0], i = 0, x = 1;
    if (len < 2)
        return;
    while(i < len) {
        if( a[i] < tmp ) {
            swap(a+x, a+i);
            x++;
        }
        i++;
    }
    swap(a, a + x - 1);
    quick_sort(a, x - 1);
    quick_sort(a + x, len - x);

    return;
}

int main(void)
{
    srand((unsigned)time(NULL));
    int* a = rand_array(17); //生成随机数组
    for (int i = 0; i < 17; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    quick_sort(a, 17);
    for (int i = 0; i < 17; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}