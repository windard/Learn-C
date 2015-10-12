#include<stdio.h>
	int main (void)
{
		int		i;
		int		k = 1;

		for(i= 1;i<=100;i++)
		{

			





			if (i%3==0)
			{	printf("%4d",i);
				k++;
			}

			if (k%10==0)
				printf("\n");	

		
		}

		return 0;
	}