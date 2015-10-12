/*******************************实心菱形***********************************
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
	return 0;
}
*****************************************************************************************/
/************************************空心菱形*********************************************
#include<stdio.h>
int main (void)
{
	int			arr[100][100]={0};
	int			i,j;
	int			m,n,p;

	printf("Please input a number :\n");
	scanf("%d",&n);

	if(n<=0||n%2==0)
		printf("Your input is wrong\n");
	else
	{
		m=p=(n+1)/2;
		for(i=0;i<(n+1)/2;i++)
		{
			arr[i][m]=1;	
			arr[i][p]=1;
			m--;
			p++;
		}
		for(;i<=(n+1);i++)
		{
			arr[i][m]=1;
			arr[i][p]=1;
			m++;
			p--;
		}
		
		for(i=0;i<=(n+1);i++)
		{
			for(j=0;j<=(2*n-1);j++)
			{
				if(arr[i][j]==1)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
********************************************************************************************/