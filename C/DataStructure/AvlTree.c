#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"AvlTree.h"

#define Max( a, b ) ( (a)>(b)?(a):(b) )
#define Min( a, b ) ( (a)<(b)?(a):(b) )

int main(void){
    

    return 0;
}

pAvlNode Insert( pAvlNode root, int data ) {
    if( root == NULL ) {
        /*Create and return a one-node tree*/
        root = (pAvlNode)malloc( sizeof( AvlNode ) );
        if( root == NULL ) {
            printf("Out of space!!!");
        } else {
            root->data = data;
            root->left = root->right = NULL;
        }
    } else {
        if( data < root->data ) {
            root->left = Insert( root->left, data );
            if( Height( root->left ) - Height( root->right ) == 2 ) {
                if( data < root->left->data ) {
                    root = SingleRotateLeft( root );
                } else {
                    root = DoubleRotateLeft( root) ;
                }
            }
        } else if( data > root->data ){
            root->right = Insert( root->right, data );
            if( Height( root->right ) - Height( root->left ) == 2 ) {
                if( data > root->right->data ) {
                    root = SingleRotateRight( root );
                } else {
                    root = DoubleRotateRight( root );
                }
            }
        }
    }
    root->height = Max( Height( root->left ), Height( root->right ) ) + 1;

    return root;
}

pAvlNode SingleRotateLeft( pAvlNode node ) {
    node->right = CreatNode( node->data, node->left->right, node->right, Max( Height(node->left->right),  Height(node->right) ) + 1 );
    node->left = node->left->left;
    node->data = node->left->data;
    free( node->left );

    return node;
}

pAvlNode SingleRotateRight( pAvlNode node ) {
    node->left = CreatNode( node->data, node->left, node->right->left, Max( Height(node->left),  Height(node->right->left) + 1 );
    node->right = node->right->right;
    node->data = node->right->data;
    free( node->right );

    return node;
}

pAvlNode DoubleRotateRight( pAvlNode node ) {

    return node;
}

pAvlNode DoubleRotateLeft( pAvlNode node ) {

    return node;
}

pAvlNode FindMax( pAvlNode node ) {
    while(node->right != NULL) {
        node = node->right;
    }

    return node;
}

pAvlNode FindMin( pAvlNode node ) {
    while(node->left != NULL) {
        node = node->left;
    }

    return node;
}

int Height( pAvlNode node ) {
    if( node == NULL ) {
        return 0;
    } else {
        return node->height;
    }
}

pAvlNode CreatNode( int data, pAvlNode left, pAvlNode right, int height ) {
    pAvlNode node = (pAvlNode)malloc( sizeof( AvlNode ) );
    node->data = data;
    node->left = left;
    node->right = right;
    node->height = height;

    return node;
}