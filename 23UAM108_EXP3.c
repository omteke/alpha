#include<stdio.h>

//insert operation
void shiftDataDown(int arr[],int pos,int lpos)
{
	int cur_pos;
	cur_pos=lpos;
	while(cur_pos>=pos)
	{
		arr[cur_pos+1]=arr[cur_pos];
		cur_pos--;
	}
}

int insert(int data,int pos,int lar[],int size, int *lpos)
{
	if(*lpos==-1)
	{
		if(pos==0)
		{
			lar[pos]=data;
			(*lpos)++;
		     return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(*lpos<size-1)
		{
			if(pos==*lpos+1)
			{
			   lar[pos]=data;
			   (*lpos)++;
			   return 1;
		    }
		    
		   	else if(pos<=*lpos)
		   	{
		    		shiftDataDown(lar, pos, *lpos);
		    		lar[pos]=data;
		    		(*lpos)++;
		    		return 1;
				}
				else
				{
					return 0;
				}
				
			}
			else
			{
				return 0;
			}
		}		
	}
	
//delete operation
	
void ShiftUp(int lar[],int pos,int lpos)
{
int cur_pos;
cur_pos=pos;
while(cur_pos<=lpos)
{
	lar[cur_pos]=lar[cur_pos+1];
	cur_pos++;
}
}


int delete(int pos,int lar[],int *lpos)
{
	if(*lpos==-1)
	{
		return 0;
	}
	else
	{
		if(pos==*lpos)
		{
			(*lpos)--;
			return 1;
		}
		else if(pos<*lpos)
		{
			ShiftUp(lar,pos,*lpos);
			(*lpos)--;
			return 1;	
		}
		else
		{
			return 0;
		}
	}
}

//search operation

int search(int lar[],int size, int key)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(lar[i]==key)
		{
			return i;
		}
	
	}
	return 0;
}


//traverse operation
	
int traverse(int lar[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t",lar[i]);
	}
}


int main()
{
	int listar[10]={12,34,12,4,6,3};
	int size=10;
	int last=7;
	int status;
	int i;
	int pos;
	int key;
	int result;
	
	printf("the elements are:\n");
	for(i=0;i<last;i++)
	{
		printf("%d\t",listar[i]);
	}
	
	//insert 
		status= insert(75,5,listar,size,&last);

	if (status) 
	{
        printf("\nInsertion successful!\n");
        printf("Array after insertion: ");
        
        for (int i = 0; i <= last; i++)
		 {
            printf("%d\t ", listar[i]);
         }
    } 
	else 
	{
        printf("Insertion failed!\n");
    }
    
    //delete
    	
	printf("\nenter the position you want to delete (starting from 0)\n");
	scanf("%d",&pos);
	
	status= delete(pos,listar,&last);
	
	if(status)
   {
	for(i=0;i<last;i++)
	{
		printf("%d\t",listar[i]);
	}
   }
   else
   {
   	printf("deletion faild");
   }
	
	//search
    printf("\nenter the element you want to search:");
    scanf("%d",&key);
	
	result = search(listar,size,key);
	
	if(result!=0)
	{
		printf("\nelement found at index(starting index from 0):%d\n",result);
	}
	
    else
    {
    	printf("\nelement not found");
	
    }
	
	//traverse
	
	
	printf("the list of elements is:\n");
	traverse(listar,size);
	
    return 0;
}

