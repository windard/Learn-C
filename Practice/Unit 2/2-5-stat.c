#include<stdio.h>
int main (void)
{
	int		a,b[10000]={0};
	int		c,i,j;
	scanf("%d",&a);
	for(i=0;i<a;i++)
		scanf("%d",&b[i]);
	scanf("%d",&c);
	for(i=0,j=0;i<a;i++)
	{
		if(b[i]<c)
			j++;
	}
	printf("%d\n",j);
	return 0;
}