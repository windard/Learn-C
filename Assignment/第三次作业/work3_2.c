#include<stdio.h>

	int main (void)
	{
		float	radius;
		float	area;
	

		radius = 2.00;
		area = 3.14*radius*radius;

		printf("radius:%.2f\n",radius);
		printf("area:  %.2f\n",area);

		return 0;
	}