/*
    ADS Assignment 2 -> operations on Binary Search Tree
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

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}


void preorder(struct node *root){
    if(root != NULL)
        return ;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
       
}

void inorder(struct node *root){
    if(root == NULL)
        return ;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
    
}

void postorder(struct node *root){
    if(root == NULL)
        return ;
    postorder(root->left);
    postorder(root->right);
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

    struct node *root,*data = NULL;
    int ch=0;
    int ch2=0;
    int ch3=0;
    int height=0;
    int cnodes=0;
    while(1){
    printf("\n\n\t\t\t***MENU***\n\n");
    printf("1.create and Insert\n2.Traversal\n3.Mirror Image\n4.Height\n5.Leaf Nodes\n6.Number of nodes\n7.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    
    switch(ch){
        
        case 1:
           do {
                printf("Enter data for the node: ");
                scanf("%d", &data);
                root = insert(root, data);

                printf("Do you want to add another node? (y/n): ");
                scanf(" %c", &ch3);
            } while (ch3 == 'y' || ch3 == 'Y');
            break;
        case 2:
            
            printf("\n1.PreOrder Traversal\n2.Inorder Traversal\n3.PostOrder Traversal\n4.LevelWise Traversal");
            printf("\nEnter your choice:");
            scanf("%d",&ch2);
            switch(ch2){
                case 1:
                    preorder(root);
                    break;
                case 2:
                    inorder(root);
                    break;
                case 3:
                    postorder(root);
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
                inorder(root);
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