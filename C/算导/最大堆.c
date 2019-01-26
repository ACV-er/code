#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct heap {
    int lenth;
    int capacity;
    int* data;
} Heap, *pHeap;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// 测试用
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

// 维护最大堆
void max_heap_keep(pHeap heap, int pos)
{
    int left = pos * 2 + 1,
        right = pos * 2 + 2,
        largest = pos;
    // printf("%d %d %d\n", pos, left, right);
    if (left < heap->lenth && heap->data[pos] < heap->data[left]) {
        largest = left;
    }
    if (right < heap->lenth && heap->data[largest] < heap->data[right]) {
        largest = right;
    }
    if (largest != pos) {
        swap(&heap->data[pos], &heap->data[largest]);
        max_heap_keep(heap, largest);
    } else {
        return; //结束递归
    }

    return;
}

// 建立最大堆
void build_max_heap(pHeap heap)
{
    int i = heap->lenth / 2;
    while (i--) {
        max_heap_keep(heap, i);
    }
}

//取出最大数
int get_max(pHeap heap)
{
    int max = heap->data[0];
    heap->data[0] = heap->data[heap->lenth - 1];
    (heap->lenth)--;
    max_heap_keep(heap, 0);

    return max;
}

//插入元素
bool insert(pHeap heap, int data)
{
    if (heap->lenth == heap->capacity) {
        heap->data = (int*)realloc(heap->data, heap->capacity * 2 * sizeof(int*));
        if (heap->data == NULL) {
            printf("内存不足");
            return false;
        }
    }

    int pos = heap->lenth;
    (heap->lenth)++;
    heap->data[pos] = data;
    int farther = (pos - 1) / 2;

    while (farther > -1 && heap->data[pos] > heap->data[farther]) {
        int t = heap->data[pos];
        heap->data[pos] = heap->data[farther];
        pos = farther;
        heap->data[pos] = t;
    }

    return true;
}

int main(void)
{
    srand((unsigned)time(NULL));
    int* a = rand_array(17); //生成随机数组
    Heap heap;
    heap.capacity = heap.lenth = 17;
    heap.data = (int*)malloc(sizeof(int*) * heap.lenth);

    //测试
    for (int i = 0; i < 17; i++) {
        heap.data[i] = a[i];
    }
    insert(&heap, 17);

    build_max_heap(&heap);
    for (int i = 0; i < 17; i++) {
        printf("%d ", get_max(&heap));
    }
    printf("\n");

    return 0;
}