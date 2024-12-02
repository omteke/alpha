#include<stdio.h>
int binarysearch(int arr[],int size,int element)
{
	int low=0;
	int high=size-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==element)
		{
			return mid;
		}
		if(arr[mid]>element)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
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
	int size=10;
	int element;
	printf("enter the element:");
	scanf("%d",&element);
	int search=binarysearch(arr,size,element);
	if(search != -1) {
        printf("The element %d is found at index %d.\n", element, search);
    } else {
        printf("The element %d was not found in the array.\n", element);
    }

    return 0;
}
