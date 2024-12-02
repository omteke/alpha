#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


struct Node* BSTinsert(struct Node* root, int data)
 {
    if (root == NULL)
	 {
        return createNode(data);
    }

    if (data < root->data)
	 {
        
        root->left = BSTinsert(root->left, data);
    } else
	 {
        root->right = BSTinsert(root->right, data);
    }

    return root;
}

void inorderTraversal(struct Node* root) 
{
    if (root != NULL)
	 {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(struct Node* root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
		
	}
}

void postorderTraversal(struct Node* root)
{
	if(root!=NULL)
	{
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d ",root->data);
		
	}
}


int main() {
    struct Node* root = NULL; 
    int n, val;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        root = BSTinsert(root, val);
    }

    printf("Inorder Traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Preorder Traversal of BST : ");
    preorderTraversal(root);
    printf("\n");
    
    printf("postorder Traversal of the BST: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

