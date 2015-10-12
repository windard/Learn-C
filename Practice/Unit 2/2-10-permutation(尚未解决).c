#include<stdio.h>
int main (void)
{
	int			i,j,k;
	for(i=0;i<1000;i++)
	{
		if(i%3==0)
			printf("%d\n",i);
	}
	return 0;
}