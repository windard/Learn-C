#include <stdio.h>

void sort(int *arr,int size)
{
	int		i;
	int     j;
	int		temp;

	for(i=0; i<size; i++)
	{
		for(j = 0; j<=size-i; j++)
		{
			if( *(arr+j) > *(arr+j+1))
			{
				temp = *(arr+j);
				*(arr+j) = *(arr+j+1);
				*(arr+j+1) = temp;
			}
			
		}
	}

}

int main(void)
{
	int    arr[] = {1,5,2,3,4};
	int    size;
	int    i;

	size = sizeof(arr)/sizeof(arr[0]);

	sort(arr,size);

	for(i=0; i<size; i++)
	{
		printf("%4d",arr[i]);

	}
	printf("\n");

	return 0;

}