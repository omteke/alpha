#include<stdio.h>
int linearsearch(int arr[],int size,int element)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==element)
		{
			return i;
		}

		}
		return -1;
        }
        

int main()
{
	int arr[10],i;
	printf("enter the array values:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
        }
	int size=9;
	int element;
	printf("enter the element:");
	scanf("%d",&element);
	int search=linearsearch(arr,size,element);
    if(search != -1) {
        printf("The element %d is found at index %d.\n", element, search);
    } 
	else {
        printf("The element %d was not found in the array.\n", element);
    }

    return 0;
}
