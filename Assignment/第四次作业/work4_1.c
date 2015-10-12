#include <stdio.h>

int main (void)
{

	float		a;


	printf("please input a number \n");
	scanf("%f",&a);

	if(a>=0)
		printf("the number is %f\n",a);
	else
	{
		a = -a ;
		printf("the number is %f\n",a);
	}
		return 0;

	}