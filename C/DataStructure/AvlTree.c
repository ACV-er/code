#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"AvlTree.h"

#define Max( a, b ) ( (a)>(b)?(a):(b) )
#define Min( a, b ) ( (a)<(b)?(a):(b) )

void inorder_traversal(pAvlNode root) { //中序遍历
  if( root == NULL) return;
  inorder_traversal(root->left);
   printf("%d ", root->data);
  inorder_traversal(root->right);

  return;
}

int main(void){
    int a[10] = { 1, 5, -9, 20, 8, 69, 93, -100, 32, 10 };
    int i;
    pAvlNode root = NULL;
    for(i=0; i<10; i++) {
        root = Insert( root, a[i] );
        // printf("%d", root->data);
    }
    // inorder_traversal(root);
    // printf("\n");

    return 0;
}

pAvlNode Insert( pAvlNode root, int data ) {
    if( root == NULL ) {
        printf("0");
        /*Create and return a one-node tree*/
        root = (pAvlNode)malloc( sizeof( AvlNode ) );
        if( root == NULL ) {
            printf("Out of space!!!");
        } else {
            root->data = data;
            root->left = root->right = NULL;
        }
    } else {
        printf("1");
        if( data < root->data ) {
            root->left = Insert( root->left, data );
            if( Height( root->left ) - Height( root->right ) == 2 ) {
                if( data < root->left->data ) {
                    SingleRotateLeft( root );
                } else {
                    DoubleRotateLeft( root) ;
                }
            }
        } else if( data > root->data ){
            root->right = Insert( root->right, data );
            if( Height( root->right ) - Height( root->left ) == 2 ) {
                if( data > root->right->data ) {
                    SingleRotateRight( root );
                } else {
                    DoubleRotateRight( root );
                }
            }
        }
    }
    root->height = Max( Height( root->left ), Height( root->right ) ) + 1;

    return root;
}

void SingleRotateLeft( pAvlNode node ) {
    node->right = CreatNode( node->data, node->left->right, node->right, Max( Height(node->left->right),  Height(node->right) ) + 1 );
    pAvlNode tmp = node->left;
    node->left = node->left->left;
    node->data = node->left->data;
    free( tmp );

    return;
}

void SingleRotateRight( pAvlNode node ) {
    node->left = CreatNode( node->data, node->left, node->right->left, Max( Height(node->left),  Height(node->right->left) ) + 1 );
    pAvlNode tmp = node->left;
    node->right = node->right->right;
    node->data = node->right->data;
    free( tmp );

    return;
}

void DoubleRotateRight( pAvlNode node ) {
    SingleRotateLeft( node->right );
    SingleRotateRight( node );

    return;
}

void DoubleRotateLeft( pAvlNode node ) {
    SingleRotateRight( node->left );
    SingleRotateLeft( node );

    return;
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