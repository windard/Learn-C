#include<stdio.h>
int main (void)
{
	int			a[100][100],i,j;
	int			M;

	printf("Please input your number : \n");
	scanf("%d",&M);

	if(M<=0)
		printf("ERROR:Your input is wrong \n");
	else
	{
		for(i=0;i<M;i++)
		{
		
			for(j=0;j<=i;j++)
			{
				if(i==j||j==0)
					a[i][j]=1;
				else
					a[i][j]=a[i-1][j]+a[i-1][j-1];
				
				printf("%5d",a[i][j]);
			}
			printf("\n");
		}
	}
	getchar();
	return 0;
}
