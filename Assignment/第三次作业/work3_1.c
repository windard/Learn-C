#include <stdio.h>

	int main (void)

	{
			float		centigrade;
			float		fahrenheit;


			centigrade =  18;
			fahrenheit =  32+centigrade*1.8;

			printf("centigrade:      %.3f\n",centigrade);
			printf("fahrenheit:      %.3f\n",fahrenheit);

			return 0;
			}