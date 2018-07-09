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
void SingleRotateLeft( pAvlNode node );
void SingleRotateRight( pAvlNode node );
void DoubleRotateLeft( pAvlNode node );
void DoubleRotateRight( pAvlNode node );
int Height( pAvlNode node );
void ShowTree( pAvlNode root );

#endif