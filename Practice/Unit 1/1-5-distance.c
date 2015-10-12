#include<stdio.h>
#include<math.h>
int main (void)
{
	float		a,b,c,d;
	double		x,y,z;
	scanf("%f%f%f%f",&a,&b,&c,&d);
	x=(a-c)*(a-c);
	y=(b-d)*(b-d);
	z=sqrt(x+y);
	printf("%.3lf\n",z);
	return 0;
}