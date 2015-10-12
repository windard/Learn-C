#include <stdio.h>

int main (void)
{
	double		sum = 0;
	int			i = 1;

	while(i<10)
	{
		sum+=1.0/i;
		i++;
	}

		printf("sum = %f\n",sum);

		return 0;

}