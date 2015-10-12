#include<stdio.h>
	int main (void)
{
		int		a;
		int		b;
		int		i;

		for(i=1000;i<10000;i++)
		{
			b = i%100;
			a = i/100;
			if(i==(a+b)*(a+b))
			printf("%d = (%d + %d)*(%d + %d)\n",i,a,b,a,b);

		}
		return 0;
	}