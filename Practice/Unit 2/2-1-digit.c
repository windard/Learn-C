#include<stdio.h>
int main (void)
{
	double			x;
	int				a;

	scanf("%lf",&x);
	a=0;
	do{
		x=x/10;
		a++;
	}while(x>1);
	printf("%d\n",a);
	return 0;
}