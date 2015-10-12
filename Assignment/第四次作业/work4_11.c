#include<stdio.h>
	int main (void)
{
		int		a;
		int		b;
		int		m = 0;

		printf("Please input a number:\n");
		scanf("%d",&a);
	
		do
		{
			m = m * 10;
			b = a % 10;
			a = a / 10;
			m = m + b;
		}
		while(a!=0);

		printf("reserve:\n");
		printf("%d\n",m);
		return 0;
	}
