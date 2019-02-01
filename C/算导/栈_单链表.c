/**
 * 没有进行优化，push pop 都释放和生成了节点 可以存一个长度，在不够的时候延长，在未达到时无需新增任何节点，只需要移动tail
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "LIST.c"

typedef struct Stack {
    pList tail;
    pList list;
} Stack, *pStack;

pStack init_stack() {
    pStack stack = (pStack)malloc(sizeof(Stack));
    stack->list = createList();
    stack->tail = stack->list;

    return stack;
}

void push(pStack stack, int data) {
    insert(stack->tail, data);

    stack->tail = stack->tail->next;
}

int top(pStack stack) {
    return stack->tail->data;
}

void pop(pStack stack) {
    pList tmp = find_parent(stack->list, stack->tail);
    free (stack->tail);
    tmp->next = NULL;
    stack->tail = tmp;
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