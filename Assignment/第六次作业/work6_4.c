#include<stdio.h>
	int main (void)
{
		char			arr[10];
		int				i;
		int				size;

		size = sizeof(arr)/sizeof(arr[1]);


		printf("Input 10 char\n");
		for(i=0;i<size;i++)
			scanf("%c",&arr[i]);
		printf("Your array is:\n");
			for(i=0;i<size;i++)
		printf("%4c",arr[i]);
			printf("\n");


		printf("The capital letters are :\n");

			for(i=0;i<size;i++)
			{
				if(arr[i]<'a')
					printf("%4c",arr[i]);
			}
			printf("\n");

		return 0;
	} 
