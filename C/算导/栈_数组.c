#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int tail;
    int * array;
    int max_len;
} Stack, *pStack;

pStack init_stack() {
    pStack stack = (pStack)malloc(sizeof(Stack));
    stack->max_len = 50;
    stack->array = (int*)malloc(sizeof(int) * stack->max_len);
    stack->tail = 0;

    return stack;
}

void push(pStack stack, int data) {
    if(stack->tail < stack->max_len - 1) {
        stack->array[stack->tail] = data;
        (stack->tail)++;
    } else {
        stack->max_len *= 2;
        stack->array = (int*)realloc(stack->array, sizeof(int) * stack->max_len);
        stack->array[stack->tail] = data;
        (stack->tail)++;
    }

    return;
}

void pop(pStack stack) {
    if(stack->tail != 0) {
        (stack->tail)--;
    }

    return;
}

int top(pStack stack) {
    return stack->array[stack->tail - 1];
}

int main(void) {
    int a[5] = { 1, 5, 4, 2, 3 };
    pStack stack = init_stack();
    for (int i = 0; i < 5; i++) {
        push(stack, a[i]);
    }
    printf("%d ", top(stack));
    pop(stack);
    printf("%d ", top(stack));
    push(stack, 8);
    printf("%d ", top(stack));

    return 0;
}