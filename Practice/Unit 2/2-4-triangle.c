#include<stdio.h>
int main (void)
{
	int		i,a,b,c;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
	for(c=0;c<i;c++)
		printf(" ");
	for(b=0;b<2*(a-i)-1;b++)
		printf("#");
	printf("\n");
	}
	return 0;
}