#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void attachBegin(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void attachMiddle(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Position must be 1 or greater.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void attachEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void detachBegin(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void detachMiddle(struct Node* head, int position) {
    if (head == NULL || position < 1) {
        printf("Position must be 1 or greater.\n");
        return;
    }

    if (position == 1) {
        detachBegin(&head);
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void detachEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(temp);
        prev->next = NULL;
    }
}

struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Attach at Beginning\n");
        printf("2. Attach in Middle\n");
        printf("3. Attach at End\n");
        printf("4. Detach at Beginning\n");
        printf("5. Detach in Middle\n");
        printf("6. Detach at End\n");
        printf("7. Search\n");
        printf("8. Traverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to attach at beginning: ");
                scanf("%d", &value);
                attachBegin(&head, value);
                break;
            case 2:
                printf("Enter value to attach in middle: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                attachMiddle(head, value, position);
                break;
            case 3:
                printf("Enter value to attach at end: ");
                scanf("%d", &value);
                attachEnd(&head, value);
                break;
            case 4:
                detachBegin(&head);
                printf("Detached from beginning.\n");
                break;
            case 5:
                printf("Enter position to detach: ");
                scanf("%d", &position);
                detachMiddle(head, position);
                break;
            case 6:
                detachEnd(&head);
                printf("Detached from end.\n");
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = search(head, value);
                if (foundNode) {
                    printf("Found node with data: %d\n", foundNode->data);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 8:
                printf("Current List: ");
                traverse(head);
                break;
            case 9:
                while (head != NULL) {
                    detachBegin(&head);
                }
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}


