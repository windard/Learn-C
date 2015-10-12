#include<stdio.h>
int main (void)
{
	double			a,b,c;
	scanf("%lf",&a);
	b=5.0/9.0;
	c=(a-32)*b;
	printf("%.3lf\n",c);
	return 0;
}