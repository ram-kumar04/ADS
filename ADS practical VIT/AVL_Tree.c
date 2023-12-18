#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int key;
    struct Node *right;
    struct Node *left;
    int height;
};

int height (struct Node *n){
    if(n==NULL)
        return 0;
    return n->height;
}

int max(int a,int b){
    return (a>b)?a:b;
}

struct Node *newnode(int key){

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;

}


/*                  Right rotation          
    y             ---------------->             x
   / \                                         / \
   x  T3          <------------------         T1  y
  / \                Left Rotation               / \
  T1 T2                                         T2 T3


*/


struct node *rightRotate(struct Node *y){
    //see the tree above
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    //perform rotation

    x->right = y;
    y->left = T2;

    // Update height

    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;

    //return new root node
    return x;
    
}

struct Node *leftRotate(struct Node *x){
    //see the tree above
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    //perform rotation

    y->left = x;
    x->right = T2;

    //Update height

    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;

    //return new root node
    return y;

}

int getBalance(struct Node *N){
    if(N == NULL)
        return 0;
    return (height(N->left)-height(N->right));
}

struct Node *insert(struct Node *node,int key){

    if(node == NULL)
        return(newnode(key));
    if(key < node->key)
        node->left = insert(node->left,key);
    if(key > node->key)
        node->right = insert(node->right,key);
    else
        return node;
    
    node->height = 1+max(height(node->left),height(node->right));

    int balance = getBalance(node);

    // Left Left rotation(LL) case
    if(balance > 1 && key < node->left->key)
        return rightRotate(node);
    
    // Right Right rotation(RR) case
    if(balance < -1 && key > node->right->key)
        return leftRotate(node);
    
    // Left Right rotation (LR) case
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left rotation (RL) case
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct Node *root){
    if(root != NULL)
    {
        printf("%d",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}



void main(){

    struct Node *root = NULL;

    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,25);

    printf("Preorder traversal of the constructed AVL tree is: \n");
    preOrder(root);

    getch();
}