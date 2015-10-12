#include<stdio.h>

	int main (void)
	{
		float	a;
		float	b;

		printf("please input the centigrade:\n");
		scanf("%f",&a);

		b = 32 + a * 1.8;
		printf("centigrade:      %.3f\n",a);
		printf("fahrenheit:      %.3f\n",b);

		return 0;

	}