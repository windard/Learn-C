#include<stdio.h>
int main (void)
{
	float		x;
	scanf("%f",&x);
	if(x<=0)
		x=-x;
	printf("%f\n",x);
	return 0;
}