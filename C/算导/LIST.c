#ifndef LIST

#define LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int data;
    struct List* next;
} List, *pList;

pList createList()
{
    pList head = (pList)malloc(sizeof(List));
    head->next = NULL;

    return head;
}

pList createNode(int data)
{
    pList List = (pList)malloc(sizeof(List));
    List->next = NULL;
    List->data = data;

    return List;
}

void insert(pList head, int data)
{
    pList st = head;
    while (st->next != NULL) {
        st = st->next;
    }
    st->next = createNode(data);
}

void delete (pList head, int data)
{
    pList st = head;
    while (st->next != NULL && st->next->data != data) {
        st = st->next;
    }
    if (st->next != NULL) {
        pList tmp = st->next;
        st->next = st->next->next;
        free(tmp);
    }
}

void traversal(pList head)
{
    pList st = head;
    while (st->next != NULL) {
        printf("%d ", st->next->data);
        st = st->next;
    }
    printf("\n");
}

pList find_parent(pList head, pList pos)
{
    pList st = head;
    while (st != NULL) {
        if (st->next == pos) {
            return st;
        } else {
            st = st->next;
        }
    }

    return st;
}

#endif