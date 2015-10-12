#include <stdio.h>

	int main (void)
{
		int		a ;

		for(a=1;a<=100;a++)
		{
			printf("%4d",a);

			if (a%10==0)
				printf("\n");
		}
	}

