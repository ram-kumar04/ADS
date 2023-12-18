/*
    ADS Assignment 1 -> operations on Binary Tree
                                            By-> Ajinkya Matre
                                                Div: C Roll-SEDA 14
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

//node creation

struct node *create(){

    int x;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter data of the node(Enter -1 if no node):");
    scanf("%d",&x);

    if(x==-1)
        return 0;

    newnode->data = x;

    printf("\nEnter left child of the %d",x);
    newnode->left = create();

    printf("\nEnter Right child of the %d",x);
    newnode->right = create();

    return newnode;
}

void Preeorder(struct node *root){
    if(root==NULL)
        return ;
    
    printf("%d",root->data);
    Preeorder(root->left);
    Preeorder(root->right);
}

void Inorder(struct node *root){
    if(root == NULL)
        return;
    
    Inorder(root->left);
    printf("%d",root->data);
    Inorder(root->right);
}


void Postorder(struct node *root){
    if(root == NULL)
        return;
    
    Postorder(root->left);
    Postorder(root->right);
    printf("%d",root->data);
}

void mirror(struct node* root) {
    if (root == NULL)
        return;
    
    // Swap left and right children
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for left and right subtrees
    mirror(root->left);
    mirror(root->right);
}

void free_tree(struct node* root) {
    // Deallocates memory corresponding
    // to every node in the tree.
    struct node* temp = root;
    if (!temp)
        return;
    free_tree(temp->left);
    free_tree(temp->right);
    if (!temp->left && !temp->right) {
        free(temp);
        return;
    }
}

int tree_height(struct node* root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
       
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void print_level(struct node* root, int level_no) {
   
    if (!root)
        return;
    if (level_no == 0) {
        
        printf("%d -> ", root->data);
    }
    else {
        
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }

}

void print_tree_level_order(struct node* root) {
    if (!root)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        printf("Level %d: ", i);
        print_level(root, i);
        printf("\n");
    }
    printf("\n\n-----Complete Level Wise Traversal:-----\n");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
}

void displayLeafNodes(struct node* root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);

    displayLeafNodes(root->left);
    displayLeafNodes(root->right);
}

int countNodes(struct node * root){
    if(root == NULL)
        return 0;

    else
        return (countNodes(root->left) + countNodes(root->right) + 1);
}

void main(){

    struct node* root;

    int ch=0;
    int ch2=0;
    int height=0;
    int cnodes=0;
    while(1){
    printf("\n\n\t\t\t***MENU***\n\n");
    printf("1.create and Insert\n2.Traversal\n3.Mirror Image\n4.Height\n5.Leaf Nodes\n6.Number of nodes\n7.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    
    switch(ch){
        case 1:
            root = create();
            break;
        case 2:
            
            printf("\n1.PreOrder Traversal\n2.Inorder Traversal\n3.PostOrder Traversal\n4.LevelWise Traversal");
            printf("\nEnter your choice:");
            scanf("%d",&ch2);
            switch(ch2){
                case 1:
                    Preeorder(root);
                    break;
                case 2:
                    Inorder(root);
                    break;
                case 3:
                    Postorder(root);
                    break;

                case 4:
                    print_tree_level_order(root);
                    break;
                default:
                    printf("Invalid input");
            }

            break;

        case 3: mirror(root);
                printf("Mirror image in form of inorder is:");
                Inorder(root);
                break;

        case 4: height = tree_height(root);
                printf("Height of the tree :%d",height);
                break;

        case 5: displayLeafNodes(root);
                break;
        case 6: cnodes = countNodes(root);
                printf("Number of nodes in tree are : %d",cnodes);
                break;
        case 7: exit(0);

        default:
            printf("Invalid input");

    }
    }

     // Free the tree!
    free_tree(root);
    getch();
}