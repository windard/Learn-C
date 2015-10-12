#include<stdio.h>
#include<math.h>
int main (void)
{
	double		n;
	double		x,y;
	scanf("%lf",&n);
	x=cos(n);
	y=sin(n);
	printf("%lf\n%lf\n",x,y);
	return 0;
}