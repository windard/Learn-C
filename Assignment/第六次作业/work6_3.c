#include<stdio.h>
	int main (void)
{
	int				arr[6] = {1,3,5,7,9};
	int				i;
	int				j;
	int				size;
	int				m;
	
	size = sizeof(arr)/sizeof(arr[1]);

	printf("Old array is :\n");

	for(i=0;i<size-1;i++)
		printf("%4d",arr[i]);
	printf("\n");

	printf("input x:\n");
	scanf("%d",&arr[i]);

	printf("New array is :\n");

	for(i=0;i<size;i++)
	{
		for(j=i;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				m=arr[i];
				arr[i]=arr[j];
				arr[j]=m;
			}
		}
	}
	
	for(i=0;i<size;i++)
	printf("%4d",arr[i]);
	
	printf("\n");
		
	return 0;
}
