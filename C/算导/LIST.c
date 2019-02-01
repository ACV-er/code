#ifndef LIST

#define LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node, *pNode;

pNode createList()
{
    pNode head = (pNode)malloc(sizeof(Node));
    head->next = NULL;

    return head;
}

pNode createNode(int data)
{
    pNode node = (pNode)malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;

    return node;
}

void insert(pNode head, int data)
{
    pNode st = head;
    while (st->next != NULL) {
        st = st->next;
    }
    st->next = createNode(data);
}

void delete (pNode head, int data)
{
    pNode st = head;
    while (st->next != NULL && st->next->data != data) {
        st = st->next;
    }
    if (st->next != NULL) {
        pNode tmp = st->next;
        st->next = st->next->next;
        free(tmp);
    }
}

void traversal(pNode head)
{
    pNode st = head;
    while (st->next != NULL) {
        printf("%d ", st->next->data);
        st = st->next;
    }
    printf("\n");
}

#endif