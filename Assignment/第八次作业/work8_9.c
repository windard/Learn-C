#include<stdio.h>
int main (void)
{	
	int			arr[]={1,2,3,4,5};
	int			i;
	int			j;
	int			*parr[5];

	for(i=0;i<5;i++)
	{
		printf("%4d",arr[i]);
		parr[i]=&arr[i];

	}
	
	printf("\n");

	for(i=4;i>=0;i--)
		printf("%4d",*parr[i]);

	printf("\n");

	return 0;

}