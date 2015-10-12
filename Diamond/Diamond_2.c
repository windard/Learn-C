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
	getchar();
}

