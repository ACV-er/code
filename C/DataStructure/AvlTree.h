#ifndef _AvlTree_H
#define _AvlTree_H

typedef struct AvlNode{
    int data;
    struct AvlNode * left;
    struct AvlNode * right;
    int height;
} AvlNode, * pAvlNode;

void MakeEmpty( AvlNode node );
pAvlNode Insert( pAvlNode root, int data );
bool Delete( pAvlNode root, int data );
pAvlNode FindMax( pAvlNode node );
pAvlNode FindMin( pAvlNode node );
bool Retrieve(int data);

pAvlNode CreatNode( int data, pAvlNode left, pAvlNode right, int height );
pAvlNode SingleRotateLeft( pAvlNode node );
pAvlNode SingleRotateRight( pAvlNode node );
pAvlNode DoubleRotateLeft( pAvlNode node );
pAvlNode DoubleRotateRight( pAvlNode node );
int Height( pAvlNode node );

#endif