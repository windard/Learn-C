#include<stdio.h>
	int main (void)
{
		int				arr[40];
		int				i;


		arr[0] = 1;
		arr[1] = 1;

		for(i=2;i<40;i++)
		{
			arr[i] = arr[i-1]+arr[i-2];
		}
		for(i=0;i<40;i++)
		{	printf("%12d",arr[i]);
			if(((i+1)%4)==0)
			printf("\n");
		}
		return 0;
	}
		