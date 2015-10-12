#include<stdio.h>
int main (void)
{
	int			a,b,c;
	double		m,n;

	scanf("%d%d%d",&a,&b,&c);
	m=a+b+c;
	n=m/3.0;
	printf("%.3lf\n",n);
	return 0;
}