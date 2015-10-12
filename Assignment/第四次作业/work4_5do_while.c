#include <stdio.h>
	int main (void)
{
		int			a=1;

		do
		{
			printf("%4d",a);
			a++;
			
			if(a%10==1)
			{	printf("\n");
			}
		}
	while (a<=100);
}