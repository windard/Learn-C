#include<stdio.h>
int main (void)
{
	double		b,x=0;
	int			a,i;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		b=1.0/i;
		x+=b;
	}
	printf("\n%.3lf\n",x);
	return 0;
}