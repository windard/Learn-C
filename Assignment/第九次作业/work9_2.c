#include<stdio.h>

void sort (int size,int *parr);

int main (void)
{
	int			arr[]={1,5,4,2,3};
	int			i;
	int			size;

	size=sizeof(arr)/sizeof(arr[0]);

	printf("The former one is :\n");

	for(i=0;i<size;i++)
	{
		printf("%4d",arr[i]);
	}

	printf("\n");

	sort(size,arr);

	printf("The later onr is :\n");

	for(i=0;i<size;i++)
	{
		printf("%4d",arr[i]);
	}
	
	printf("\n");

	return 0;
}

void sort (int size,int *parr)
{
	int			i;
	int			j;
	int			temp;


	for(i=0;i<size;i++,parr++)
	{
		for(j=0;j<size-i;j++)
		{
			if(*parr>*(parr+j))
			{
				temp=*parr;
				*parr=*(parr+j);
				*(parr+j)=temp;

			}
		}
	}

	return;
}