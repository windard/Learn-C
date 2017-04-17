/***********************************实心菱形*************************************************
#include<stdio.h>
int main()
{
	int i,j;
	int n;

	printf("Please input a number : \n");
	scanf("%d",&n);

	if(n<=0||n%2==0)
		printf("ERROR:Your input is wrong \n");
	else
	{
		for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					if(i+j>=(n-1)/2 && i+j<=3*(n-1)/2 && i-j<=(n-1)/2 && j-i<=(n-1)/2)	
						printf("*");
					else
						printf(" ");

					printf("\n");
			}
	}
	
	return 0;
}
************************************************************************************/
/**********************************空心菱形*************************************************
#include<stdio.h>
int main()
{
	int i,j;
	int n;

	printf("Please input a number : \n");
	scanf("%d",&n);

	if(n<=0||n%2==0)
		printf("ERROR:Your input is wrong \n");
	else
	{
		for(i=0;i<n;i++)
				{
				for(j=0;j<n;j++)
				{
					if(i+j==(n-1)/2 || i+j==3*(n-1)/2 || i-j==(n-1)/2 || j-i==(n-1)/2 )
					{	
						printf("*");
					}
					else
						printf(" ");
				}
					printf("\n");
				}
	}	
	return 0;
}
*************************************************************************************/
