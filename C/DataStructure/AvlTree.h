#ifndef _AvlTree_H
#define _AvlTree_H

typedef struct AvlNode AvlNode;
typedef AvlNode * pAvlNode;

void MakeEmpty( AvlNode node );
pAvlNode Insert( pAvlNode root, int data );
pAvlNode Delete( pAvlNode root, int data );
pAvlNode FindMax( pAvlNode node );
pAvlNode FindMin( pAvlNode node );
bool Retrieve(int data);

struct AvlNode{
    int data;
    struct AvlNode * left;
    struct AvlNode * right;
    int height;
};

#endif