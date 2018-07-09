#ifndef _SplayTree_H
#define _SplayTree_H

typedef struct SplayNode SplayNode;
typedef SplayNode * pSplayNode;


struct SplayNode{
    int data;
    pSplayNode left;
    pSplayNode right;
};

pSplayNode Insert( pSplayNode root, int data );
pSplayNode Delete( pSplayNode root, int data );
pSplayNode Find( pSplayNode root, int data );
pSplayNode FindMin( pSplayNode root );
pSplayNode FindMax( pSplayNode root );

#endif