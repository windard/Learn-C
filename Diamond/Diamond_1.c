#include<stdio.h>
int main (void)
{
	int		i;
	int		j;
	int		k;
	int		n;

	printf("Please input a number :\n");
	scanf("%d",&n);

	if(n<=0||n%2==0)
		printf("Your input is wrong\n");
	else
	{
		for(i=1;i<=(n+1)/2;i++)
		{
			for(j=1;j<=((n+1)/2-i);j++)
			{
				printf(" ");
			}
			
			for(k=1;k<=(2*i-1);k++)
				printf("*");

			printf("\n");
		}
		for(i=1;i<(n+1)/2;i++)
		{
			for(j=1;j<=i;j++)
			{
				printf(" ");
			}
			
			for(k=1;k<=(n-2*i);k++)
				printf("*");

			printf("\n");
		}

	}

	getchar();
	return 0;
}

