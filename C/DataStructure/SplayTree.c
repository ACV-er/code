#include<stdio.h>
#include<stdlib.h>
#include"SplayTree.h"

pSplayNode CreatNode( int data, pSplayNode left, pSplayNode right );

int main(void) {
    

    return 0;
}

pSplayNode Insert( pSplayNode root, int data ) {
    pSplayNode st = root;
    while( st != NULL ) {
        if( data > st->data ) {
            if( st->right == NULL ) {
                st->right = CreatNode( data, NULL, NULL );
                break;
            } else {
                st = st->right;
            }
        } else if( data < st->data ) {
            if( st->left == NULL ) {
                st->left = CreatNode( data, NULL, NULL );
                break;
            } else {
                st = st->left;
            }
        } else {
            // printf("该数据已存在--（%d）", data);
            break;
        }
    }
    if( st == NULL ) {
        root = CreatNode( data, NULL, NULL );
    }

    return root;
}

pSplayNode Delete( pSplayNode root, int data ) {
    if( root == NULL ) {
        printf("树为空或无此元素");
    } else {
        if( data > root->data ) {
            root->right = Delete( root->right, data );
        } else if( data < root->data ) {
            root->left = Delete( root->left, data );
        } else {
            if( root->left && root->right ) {
                pSplayNode tmp = FindMin( root->right );
                root->data = tmp->data;
                root->right = Delete( root->right, tmp->data );
            } else if( root->left ) {
                pSplayNode tmp = root->left;
                root->data = tmp->data; root->left = tmp->left; root->right = tmp->right; //将tmp赋值给该节点则删除tmp则模拟保留tmp并删除该节点
                free( tmp );
            } else if( root->right ) {
                pSplayNode tmp = root->right;
                root->data = tmp->data; root->left = tmp->left; root->right = tmp->right; //将tmp赋值给该节点则删除tmp则模拟保留tmp并删除该节点
                free( tmp );
            } else {
                free( root );
                root = NULL;
            }
        }
    }

    return root;
}

pSplayNode FindMin( pSplayNode root ) {
    while( root->left != NULL ) {
        root = root->left;
    }
    
    return root;
}

pSplayNode FindMax( pSplayNode root ) {
    while( root->right != NULL ) {
        root = root->right;
    }
    
    return root;
}

pSplayNode Find( pSplayNode root, int data ) {
    
}

pSplayNode CreatNode( int data, pSplayNode left, pSplayNode right ) {
    pSplayNode node = (pSplayNode)malloc( sizeof( SplayNode ) );
    node->data = data;
    node->left = left;
    node->right = right;

    return node;
}