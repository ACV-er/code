#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"SplayTree.h"

pSplayNode CreatNode( int data, pSplayNode left, pSplayNode right );
void Splay( pSplayNode root, int data );
void SingleRotateRight( pSplayNode node );
void SingleRotateLeft( pSplayNode node );
void ShowTree( pSplayNode root );

struct WithFartherData{
    int fartherdata;
    pSplayNode self;
};

int height( pSplayNode root ) {
    if( root == NULL ) {
        return 0;
    } else {
        return (height(root->right)>height(root->left))?height(root->right)+1:height(root->left)+1;
    }
}

int main(void) {
    int i;
    pSplayNode root = NULL;
    for(i = 32; i > 0; i--) {
        root = Insert(root , i);
    }
    ShowTree( root );
    printf("\n");
    Find( root, 1 );
    ShowTree( root );
    printf("\n");
    Find( root, 2 );
    ShowTree( root );
    printf("\n");
    Find( root, 3 );
    ShowTree( root );
    printf("\n");
    Find( root, 4 );
    ShowTree( root );
    printf("\n");
    printf("\n%d\n", height(root));
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
    pSplayNode st = root;
    while (st != NULL) {
        if(st->data == data) {
            break;
        } else if ( st->data < data ) {
            st = st->right;
        } else {
            st = st->left;
        }
    }
    if( st != NULL ) Splay( root, data );

    return st;
}

void Splay( pSplayNode root, int data ) {
    pSplayNode node[100];
    int st = 0;
    
    while( true ) {
        node[st++] = root;
        if( root->data == data ) {
            break;
        } else if( root->data > data ) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    st -= 2;//往下一格是那个节点本身
    pSplayNode gfather, father;
    while( st > 0 ) {
        father = node[st--];
        gfather = node[st--];
        if( data > gfather->data ) {
            if( data > father->data ) { //旋转第一次后，他的祖父节点变为它的父节点
                SingleRotateRight(gfather);
                SingleRotateRight(gfather);
            } else {
                SingleRotateLeft(father);
                SingleRotateRight(gfather);
            }
        } else {
            if( data < father->data ) {
                SingleRotateLeft(gfather);
                SingleRotateLeft(gfather);
            } else {
                SingleRotateRight(father);
                SingleRotateLeft(gfather);
            }
        }
    }
    if( st == 0 ) {
        if( data > node[st]->data) {
            SingleRotateRight(node[st]);
        } else {
            SingleRotateLeft(node[st]);
        }
    }

    return;
}

pSplayNode CreatNode( int data, pSplayNode left, pSplayNode right ) {
    pSplayNode node = (pSplayNode)malloc( sizeof( SplayNode ) );
    node->data = data;
    node->left = left;
    node->right = right;

    return node;
}

void SingleRotateLeft( pSplayNode node ) {//普通单旋转，使根节点变成它的右节点，并且使其的左节点为原本左节点的右节点，使左节点变成根节点，解决左节点左边突出
    node->right = CreatNode( node->data, node->left->right, node->right );//复制一个自己成为自己的右节点节
    pSplayNode tmp = node->left;//存储它的左节点
    node->data = node->left->data;//把它的左节点变为根节点
    node->left = node->left->left;//维持原来的左节点本身的根节点
    free( tmp );//既然左节点用复制的方式成为了根节点，那么真正的左节点删除即可

    return;
}

void SingleRotateRight( pSplayNode node ) {
    node->left = CreatNode( node->data, node->left, node->right->left );
    pSplayNode tmp = node->right;
    node->data = node->right->data;
    node->right = node->right->right;
    free( tmp );

    return;
}

void ShowTree( pSplayNode root ) {
    struct WithFartherData queue[100];
    int st, end;
    st = end = 0;
    queue[end].fartherdata = 0;
    queue[end++].self = root;
    while( st != end ) {
        if( queue[st].self->left != NULL ) {
            queue[end].fartherdata = queue[st].self->data;
            queue[end++].self = queue[st].self->left;
        }
        if( queue[st].self->right != NULL ) {
            queue[end].fartherdata = queue[st].self->data;
            queue[end++].self = queue[st].self->right;
        }
        if( queue[st].self->data < queue[st].fartherdata ) {
            printf("%d(%d) ", queue[st].self->data, queue[st].fartherdata);
        } else {
            printf("(%d)%d ", queue[st].fartherdata, queue[st].self->data );
        }
        st++;
        if(end > 99) end = end%99;
        if(st > 99) st = st%99;
    }
    
    return;
}