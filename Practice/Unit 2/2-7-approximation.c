#include<stdio.h>
int main (void)
{
	int			i=1,j,a=1;
	double		b,m=0,n;
	while(1)
	{
		j=2*i-1;
		b=1.0/j;
		m+=a*b;
		a=-a;
		i++;
		if(b<=0.0000001)
			break;
	}
	n=4*m;
	printf("%lf\n",n);
	return 0;
}