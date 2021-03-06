#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"AvlTree.h"

#define Max( a, b ) ( (a)>(b)?(a):(b) )
#define Min( a, b ) ( (a)<(b)?(a):(b) )

pAvlNode CreatNode( int data, pAvlNode left, pAvlNode right, int height );
void SingleRotateLeft( pAvlNode node );
void SingleRotateRight( pAvlNode node );
void DoubleRotateLeft( pAvlNode node );
void DoubleRotateRight( pAvlNode node );
int Height( pAvlNode node );
void ShowTree( pAvlNode root );

struct WithFartherData{
    int fartherdata;
    pAvlNode self;
};

int h(pAvlNode node) {
    if(node == NULL) {
        return 1;
    } else {
        return Max(h(node->left), h(node->right)) + 1;
    }
}

void inorder_traversal(pAvlNode root) { //中序遍历
    if( root == NULL) return;
    inorder_traversal(root->left);
    printf("%d ", root->data);
    if( ( h( root->left ) - h( root->right ) > 1 ) || ( h( root->right ) - h( root->left ) > 1 ) ) {
        printf("error");
    }
    inorder_traversal(root->right);

    return;
}

int main(void){
    int a[10] = { 1, 5, -9, 20, 8, 69, 93, -100, 32, 10 };
    int i;
    pAvlNode root = NULL;
    for(i=0; i<10; i++) {
        root = Insert( root, a[i] );
    }
    inorder_traversal(root);
    printf("\n");
    ShowTree(root);
    printf("\n");
    root = Delete(root, 93);
    ShowTree(root);
    printf("\n");

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

pAvlNode Delete( pAvlNode root, int data ) { //删除与插入基本一致，左树删除与右树插入结果一致
    if( root == NULL ) return false;
    if( data < root->data ) {
        root->left = Delete( root->left, data);
        if( Height( root->right ) - Height( root->left ) == 2 ) {
            if( data < root->right->data ) {
                SingleRotateRight( root );
            } else {
                DoubleRotateRight( root );
            }
        }
    } else if( data > root->data ){
        root->right = Delete( root->right, data );
        if( Height( root->left ) - Height( root->right ) == 2 ) {
            if( data > root->left->data ) {
                SingleRotateLeft( root );
            } else {
                DoubleRotateLeft( root) ;
            }
        }
    } else {
        if( root->left && root->right ) {
            pAvlNode tmp = FindMin(root->right);
            root->data = tmp->data; 
            Delete( root->right, tmp->data );
        } else if( root->left ) {
            pAvlNode tmp = root->left;
            root->data = tmp->data;
            root->left = tmp->left;
            root->right = tmp->right;
            free( tmp );
        } else if( root->right ) {
            pAvlNode tmp = root->right;
            root->data = tmp->data;
            root->left = tmp->left;
            root->right = tmp->right;
            free( tmp );
        } else {
            free( root );
            return NULL;
        }
    }

    root->height = Max( Height( root->left ), Height( root->right ) ) + 1;
    
    return root;
}

void SingleRotateLeft( pAvlNode node ) {//普通单旋转，使根节点变成它的右节点，并且使其的左节点为原本左节点的右节点，使左节点变成根节点，解决左节点左边突出
    node->right = CreatNode( node->data, node->left->right, node->right, Max( Height(node->left->right),  Height(node->right) ) + 1 );//复制一个自己成为自己的右节点节
    pAvlNode tmp = node->left;//存储它的左节点
    node->data = node->left->data;//把它的左节点变为根节点
    node->left = node->left->left;//维持原来的左节点本身的根节点
    free( tmp );//既然左节点用复制的方式成为了根节点，那么真正的左节点删除即可

    return;
}

void SingleRotateRight( pAvlNode node ) {
    node->left = CreatNode( node->data, node->left, node->right->left, Max( Height(node->left),  Height(node->right->left) ) + 1 );
    pAvlNode tmp = node->right;
    node->data = node->right->data;
    node->right = node->right->right;
    free( tmp );

    return;
}

void DoubleRotateRight( pAvlNode node ) {//右双旋转
    SingleRotateLeft( node->right ); //把右节点左边的突出移到右边
    SingleRotateRight( node ); //当做正常的右节点右边突出

    return;
}

void DoubleRotateLeft( pAvlNode node ) { //解释对应右双旋转
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

void ShowTree( pAvlNode root ) {
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