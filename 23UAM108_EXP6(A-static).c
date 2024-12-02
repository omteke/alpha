#include<stdio.h>

int push(int starr[],int *sttop, int stsize,int data)
{ 
	if(*sttop>=stsize-1)
	{
		printf("stack full");
	}
	else
	{
		(*sttop)++;
		starr[*sttop]=data;
		
		
	}
}

int pop(int starr[],int *sttop,int *retdata)
{
	int value;
	if(*sttop==-1)
	{
		printf("stack empty cannot pop %d",*retdata);
	}
	else
	{
	    value=starr[*sttop];
	    (*sttop)--;
	    *retdata=value;
	    return(*retdata);
	    
	    
	}
}
void display(int *top,int starr[])
{
	int i;
	if(*top==-1)
	{
		printf("stack empty");
	}
	else
	{  printf("stack elements are \n");
		for(i=*top;i>=0;i--)
		{
			printf("\t%d \n ",starr[i]);
		}
		
	}
}


int main()
{
	int stack[6];
	int size=6;
	int top=-1;
	int data;
	int retdata;
	printf("enter the data to push \n");
	scanf("%d",&data);
    push(stack,&top,size,data);
    
	scanf("%d",&data);
    
    push(stack,&top,size,data);
   
	scanf("%d",&data);
    push(stack,&top,size,data);
   
	scanf("%d",&data);
    push(stack,&top,size,data);
   
	scanf("%d",&data);
    push(stack,&top,size,data);
   
	
    display(&top,stack);
    
    pop(stack,&top,&retdata);
    printf("after popped \n");
    display(&top,stack);
    
   
	
	
}
