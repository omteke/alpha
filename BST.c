#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data) 
{
    struct node* nnode;
    nnode = (struct node*) malloc(sizeof(struct node));
    nnode->data = data;
    nnode->left = NULL;
    nnode->right = NULL;
    return nnode;
}

struct node* BSTInsert(struct node* root, int data) 
{
    if (root == NULL) 
	{
        root = create_node(data);
        return root;
    } 
	else 
	{
        if (data < root->data) 
		{
            root->left = BSTInsert(root->left, data);
        } 
		else if (data > root->data) 
		{
            root->right = BSTInsert(root->right, data);
        }
        return root;
    }
}
void printTree(struct node* root) 
{
    if (root != NULL) 
	{
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

void inorderTraversal(struct node* root) 
{
    if (root != NULL) 
	{
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node* root) 
{
    if (root != NULL) 
	{
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node* root) 
{
    if (root != NULL) 
	{
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    int data,choice;
    struct node* root;
    root = create_node(10);
    root->left = create_node(20);
    root->right = create_node(30);
    
    printf("\n1.BST insertion \n2.pre-order traversal \n3.in-order traversal \n4.post-order traversal");
    
    printf("enter your choice:");
    scanf("%d",&choice);
    
    switch(choice)
    {
    	case 1 : printf("Enter the data for insertion: ");
			     scanf("%d", &data);
			     root = BSTInsert(root, data);
			     printf("Binary Search Tree (inorder traversal): ");
			     printTree(root);
			     printf("\n"); 
			     break;
			     
	    case 2 : printf("Pre-order Traversal: ");
    			 inorderTraversal(root);
       			 break;
       			 
       	case 3 : printf("In-order Traversal: ");
    			 inorderTraversal(root);
    			 break;
    			 
    	case 4 : printf("In-order Traversal: ");
    			 inorderTraversal(root);
    			 break;
    			
	}
}
