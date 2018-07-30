#include<stdio.h>
#include<stdlib.h>

#define Max(x, y) ( ( (x)>(y) ) ?(x):(y) )
#define INTMIN -2147483647


struct Max_SubArray{
    int left;
    int right;
    int sum;
};

typedef struct Max_SubArray Max_SubArray;
typedef Max_SubArray * pMax_SubArray;

// 递归版
// pMax_SubArray FindMax(int *arr, int low, int high);

//简洁版
pMax_SubArray FindMax( int * arr, int len );


int main(void) {
    int a[16] = {13, -3, -25, 25, -3, -16, -23, -5, -4, -7, 12, 18, -22, 15, 20, 7};
    pMax_SubArray max = FindMax(a, 16);
    printf("%d\n", max->left );
    printf("%d\n", max->right );
    printf("%d\n", max->sum );

    return 0;
}
// 递归版
// pMax_SubArray Find_Max_Cross_Mid(int *arr, int low, int high) {
//     int i, max = INTMIN, sum = 0;
//     int mid = (low+high)/2;
//     pMax_SubArray max_arr = (pMax_SubArray)malloc( sizeof( Max_SubArray ) );
//     max_arr->left = max_arr->right = mid;
//     for( i=mid; i>=low; i-- ) {
//         sum += arr[i];
//         if( sum > max ) {
//             max = sum;
//             max_arr->left = i;
//         }
//     }
//     max_arr->sum = max;
//     sum = 0;
//     max = 0; //这里貌似不能重置为一个极小值，因为需要考虑右侧无正值
//     for( i=mid+1; i<high; i++ ) {
//         sum += arr[i];
//         if( sum > max ) {
//             max = sum;
//             max_arr->right = i;
//         }
//     }
//     max_arr->sum += max;

//     return max_arr;
// }

// pMax_SubArray FindMax(int *arr, int low, int high) {
//     if( low == high ) {
//         pMax_SubArray max_arr = (pMax_SubArray)malloc( sizeof( Max_SubArray ) );
//         max_arr->sum = arr[low];
//         max_arr->left = max_arr->right = low;
//         return max_arr;
//     }
//     int mid = (low+high)/2;
//     pMax_SubArray max_cross = Find_Max_Cross_Mid( arr, low, high );
//     pMax_SubArray max_left = FindMax( arr, low, mid );
//     pMax_SubArray max_right = FindMax( arr, mid+1, high );

//     if( max_left->sum >= max_right->sum &&  max_left->sum >= max_cross->sum ) {
//         return max_left;
//     } else if ( max_right->sum >= max_left->sum &&  max_right->sum >= max_cross->sum ) {
//         return max_right;
//     } else {
//         return max_cross;
//     }
// }

// 简洁版本

pMax_SubArray FindMax( int * arr, int len ) {
    int i, tmp = arr[0], begin;
    pMax_SubArray max = (pMax_SubArray)malloc( sizeof( Max_SubArray ) );
    begin = max->right = max->left = 0;
    max->sum = arr[0];
    for( i = 1; i<len; i++ ) {
        tmp += arr[i];
        if( tmp > max->sum ) {
            max->sum = tmp;
            max->left = begin;
            max->right = i;
        }
        if( tmp < 0 ) {
            begin = i+1;
            tmp = 0;
        }
    }

    return max;
}