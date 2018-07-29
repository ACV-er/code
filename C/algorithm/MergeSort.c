#include<stdio.h>
#include<stdlib.h>
#define min(a,b) (a<b?a:b)

#define INT_MAX 2147483647
// void merge_sort(int * arr, int len); //迭代版
void merge_sort( int * arr, int begin, int end ); //递归版
int main(void) {
    // printf("%d\n", min(10,5));
    int a[10] = {1, 6, 9, 8, 45, -10, 55, 2, 3, 96};
    // merge_sort(a, sizeof(a)/sizeof(int) );
    merge_sort(a, 0, 10);
    for(int i = 0; i<10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

// 非递归版, 参照维基百科
// void merge_sort(int * arr, int len) {
//     int * tmp = (int*)malloc( sizeof(int) * len );
//     int size, start, i;//size当前归并的每个小组的大小,start和end为每次归并的始末 
//     for( size=1; size<len; size*=2 ) {
//         for( start=0; start<len; (start += size*2) ) {
//             int k = start;
//             int begin1 = start, end1 = min(len, start+size);
//             int begin2 = end1, end2 = min(len, begin2+size);
//             while (begin1 < end1 && begin2 < end2) {
// 				tmp[k++] = arr[begin1] < arr[begin2] ? arr[begin1++] : arr[begin2++];
//             }
// 			while (begin1 < end1) {
// 				tmp[k++] = arr[begin1++];
//             }
// 			while (begin2 < end2) {
// 				tmp[k++] = arr[begin2++];
//             }
//             for( i=start; i<end2; i++ ) {
//                 arr[i] = tmp[i];
//             }
//         }
//     }
//     free(tmp);

//     return;
// }

// 递归版
void merge_sort( int * arr, int begin, int end ) {
    if( end-begin > 1 ) {
        int mid = (int)( (end+begin)/2 );
        merge_sort( arr, begin, mid );
        merge_sort( arr, mid, end);
        int begin2 = mid;
        int * tmp = (int*)malloc( sizeof(int) * (end-begin) );
        int k = 0;
        while( begin<mid && begin2<end ) {
            tmp[k++] = arr[begin] < arr[begin2] ? arr[begin++] : arr[begin2++];
        }
        while( begin<mid ) {
            tmp[k++] = arr[begin++];
        }
        while( begin2<end ) {
            tmp[k++] = arr[begin2++];
        }
        for( begin = end-k, k=0; begin<end; begin++ ) {
            arr[begin] = tmp[k++];
        }
        free(tmp);
    }

        return;
}