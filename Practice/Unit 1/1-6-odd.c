#include<stdio.h>
int main (void)
{
	int			x;
	double		m;
	scanf("%d",&x);
	if(x<4)
	{
		m=95*x;
	}
	else
	{
		m=(95*x)*0.85;
	}
	printf("%.2lf\n",m);
	return 0;
}