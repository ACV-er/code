#include<stdio.h>
#include<stdlib.h>

// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出：7 -> 0 -> 8
// 原因：342 + 465 = 807

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;
typedef struct ListNode* pnode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    pnode ll = l1;

    int sum = l1->val + l2->val;
    while( l1->next && l2->next ) {
        l1->val = sum%10;
        l1->next->val += sum/10;
        l1 = l1->next; l2 = l2->next;
        sum = l1->val + l2->val;
    }
    if( l1->next == NULL ) {
        l1->next = l2->next;
    }
    l1->val = sum%10;
    while( l1->next ) {
        l1->val = sum%10;
        l1 = l1->next;
        l1->val += sum/10;
        sum = l1->val;
    }
    if( sum > 9 ) {
        li->val = sum % 10;
        l1->next = (pnode)malloc(sizeof(node));
        l1->next->val = 1;
        l1->next->next = NULL;
    }

    return ll;
}

int main(void) {
    
    pnode l1 = (pnode)malloc(sizeof(node));
    l1->val = 5;
    l1->next = (pnode)malloc(sizeof(node));
    l1->next->val = 0;
    l1->next->next = (pnode)malloc(sizeof(node));
    l1->next->next->val = 0;
    l1->next->next->next = NULL;
    pnode l2 = (pnode)malloc(sizeof(node));
    l2->val = 5;
    l2->next = (pnode)malloc(sizeof(node));
    l2->next->val = 0;
    l2->next->next = (pnode)malloc(sizeof(node));
    l2->next->next->val = 0;
    l2->next->next->next = NULL;
    l1->next = l2->next = NULL;
    
    pnode l3 = addTwoNumbers(l1, l2);

    // printf( " %d %d %d %d\n", l3->val, l3->next->val, l3->next->next->val , l3->next->next->next==NULL?3:l3->next->next->next->val);
    printf( " %d\n", l3->val);
    return 0;
}

