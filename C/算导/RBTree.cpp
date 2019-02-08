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
    pRBNode tmp = createRBNode(NULL, NULL, NULL, 0, 'n');
    T->nil = createRBNode(tmp, tmp, tmp, 0, 'b');
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
        root = node->right = createRBNode(node, T->nil, T->nil, data, 'r');
    } else {
        root = node->left = createRBNode(node, T->nil, T->nil, data, 'r');
    }

    if(node != T->root){
        RBInsertFixup(T, root);
    }
}

void showTree(pRBNode root)
{
    if (root->left != NULL) {
        showTree(root->left);
    }
    if(root->data != 0) {
        printf("%d(%d %c) ", root->data, root->parent->data, root->color);
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
    if(node == T->root) {
        return;
    }
    while(node->parent->color == 'r') {
        if(node->parent == node->parent->parent->left) {  //父节点为左节点
            pRBNode uncle = node->parent->parent->right;
            if(uncle->color == 'r') {                       //情况1叔节点为红 则把父节点的父节点涂红 父节点与叔节点涂黑，
                node->parent->color = 'b';                 //此时只有可能祖父节点与父节点同时为红，所以转而处理这个问题
                node->parent->parent->color = 'r';
                uncle->color = 'b';
                node = node->parent->parent;
            } else {       //情况二又有两种情况，需要node为父节点的左节点(与父节点相同)
                if(node == node->parent->right) {//此时为转化为node为父节点的子节点且父节点与子节点同为红
                    node = node->parent;                       
                    leftRotate(T, node);
                }
                node->parent->color = 'b';
                node->parent->parent->color = 'r';
                rightRotate(T, node->parent->parent);
            }
        } else { //和上面对称
            pRBNode uncle = node->parent->parent->left;
            if(uncle->color == 'r') {
                node->parent->color = 'b';
                node->parent->parent->color = 'r';
                uncle->color = 'b';
                node = node->parent->parent;
            } else {
                if(node == node->parent->left) {
                    node = node->parent;                       
                    rightRotate(T, node);
                }
                node->parent->color = 'b';
                node->parent->parent->color = 'r';
                leftRotate(T, node->parent->parent);
            }
        }
    }
    T->root->color = 'b';
    return;
}

int main(void)
{
    pRBTree T = createRBTree();
    int a[8] = { 10, -5, 99, 85, 12, 35, 68, 11 };
    for (int i = 0; i < 8; i++) {
        insert(T, a[i]);
    }
    showRBTree(T);

    return 0;
}
