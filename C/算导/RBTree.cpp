#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct RBNode {
    struct RBNode* parent;
    struct RBNode* left;
    struct RBNode* right;
    int data;
    char color;
} RBNode, *pRBNode;

typedef struct RBTree {
    struct RBNode* root;
    struct RBNode* nil;
} RBTree, *pRBTree;

pRBNode createRBNode(pRBNode parent, pRBNode left, pRBNode right, int data, char color);
pRBTree createRBTree(void);
void RBInsertFixup(pRBTree T, pRBNode node);

pRBTree createRBTree(void)
{
    pRBTree T = (pRBTree)malloc(sizeof(RBTree));
    T->nil = createRBNode(NULL, NULL, NULL, 0, 'b');
    T->root = T->nil;
    return T;
}

pRBNode createRBNode(pRBNode parent, pRBNode left, pRBNode right, int data, char color)
{
    pRBNode node = (pRBNode)malloc(sizeof(RBNode));
    node->parent = parent;
    node->left = left;
    node->right = right;
    node->data = data;
    node->color = color;

    return node;
}

void insert(pRBTree T, int data)
{
    pRBNode root = T->root;
    pRBNode node = T->nil;

    while (root != T->nil) {
        node = root;
        if (data > root->data) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    if (node == T->nil) {
        T->root = createRBNode(T->nil, T->nil, T->nil, data, 'b');
    } else if (data > node->data) {
        node->right = createRBNode(node, T->nil, T->nil, data, 'r');
    } else {
        node->left = createRBNode(node, T->nil, T->nil, data, 'r');
    }

    RBInsertFixup(T, root);
}

void showTree(pRBNode root)
{
    if (root->left != NULL) {
        showTree(root->left);
    }
    if(root->parent != NULL) {
        printf("%d ", root->data);
    }
    if (root->right != NULL) {
        showTree(root->right);
    }
}

void showRBTree(pRBTree T)
{
    showTree(T->root);
    printf("\n");
}

void leftRotate(pRBTree T, pRBNode node)
{
    if (node == T->nil) {
        printf("error!不存在该节点\n");
        return;
    }
    pRBNode tmp = node->right;
    if (tmp == T->nil) {
        printf("error!无法左旋转，该节点无右子节点,或该节点不存在\n");
        return;
    }
    node->right = tmp->left;
    if (node->right != T->nil) {
        node->right->parent = node;
    }
    tmp->parent = node->parent;
    tmp->left = node;
    node->parent = tmp;

    if (tmp->parent == T->nil) {
        T->root = tmp;
    } else {
        if (tmp->parent->left == node) {
            tmp->parent->left = tmp;
        } else {
            tmp->parent->right = tmp;
        }
    }
}

void rightRotate(pRBTree T, pRBNode node)
{
    if (node == T->nil) {
        printf("error!不存在该节点\n");
        return;
    }
    pRBNode tmp = node->left;
    if (tmp == T->nil) {
        printf("error!无法左旋转，该节点无右子节点,或该节点不存在\n");
        return;
    }
    node->left = tmp->right;
    if (node->left != T->nil) {
        node->left->parent = node;
    }
    tmp->parent = node->parent;
    tmp->right = node;
    node->parent = tmp;

    if (tmp->parent == T->nil) {
        T->root = tmp;
    } else {
        if (tmp->parent->left == node) {
            tmp->parent->left = tmp;
        } else {
            tmp->parent->right = tmp;
        }
    }
}

void RBInsertFixup(pRBTree T, pRBNode node)
{
    
    return;
}

int main(void)
{
    pRBTree T = createRBTree();
    int a[8] = { 10, -5, 99, 85, 10, 35, 68, 10 };
    for (int i = 0; i < 8; i++) {
        insert(T, a[i]);
    }
    showRBTree(T);
    leftRotate(T, T->root);
    rightRotate(T, T->root->left);
    showRBTree(T);

    return 0;
}
