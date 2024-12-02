#include<stdio.h>
int main()
{
	int temp,n,i,j,k;
	printf("enter the size of array:");
	scanf("%d",&n);
	
	int a[n];
	
	printf("enter the elements of the array \n");
	
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
	    }
	    
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				
				for(k=0;k<n;k++)
	            {
	
                  	printf(" %d ",a[k]);
                  	
				
		        }
		        printf("\n");
			}
		}
	} 
	
	printf("\n the sorted array is \n"); 
	for(i=0;i<n;i++)
	{
	
      	printf(" %d ",a[i]);
    }
	
	return 0;
} 
