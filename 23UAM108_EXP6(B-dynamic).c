#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **top, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *top;  
    *top = newNode;        
}

void traverse(struct Node *top) {
    if (top == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    
    struct Node *current = top;
    printf("Stack elements are: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *stackTop = NULL;  
    
    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);
    push(&stackTop, 60);
    push(&stackTop, 70);

    traverse(stackTop);

    return 0;  // Corrected this line
}

