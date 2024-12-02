#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void enqueue(struct Node**rear,struct Node**front,int data)
{
	struct Node* newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->next=NULL;
	if(*front==NULL && *rear==NULL)
	{
		*front=*rear=newnode;
		(*rear)->next=*front;
	}
	else
	{
		(*rear)->next=newnode;
		(*rear)=newnode;
		(*rear)->next=*front;
	}
}

int dequeue(struct Node **rear,struct Node**front)
{
   struct Node *tmp;
   tmp=*front;
   int data;
   if(*front==0 && *rear==0)
   {
   	return -1;
   }
   else if(*front==*rear)
   {
   	data=(*front)->data;
   	free(tmp);
   	(*front)=(*rear)=NULL;
   }
   else{
   	data=(*front)->data;
   	(*front)=(*front)->next;
   	(*rear)->next=(*front);
   	free(tmp);
   }
   	
  }
 

void displayQueue(struct Node*front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main()
{
	struct Node*front= NULL;
	struct Node*rear= NULL;
	
	
	enqueue(&rear,&front,10);
	enqueue(&rear,&front,12);
	displayQueue(front);
	dequeue(&rear,&front);
	displayQueue(front);
	enqueue(&rear,&front,10);
    displayQueue(front);
	return 0;
	
}

