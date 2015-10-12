#include<stdio.h>
#include<math.h>

	int main (void)
	{
		float	a;
		float	b;
		float	c;
		float	d;
		float	s;

		a = 3.00;
		b = 4.00;
		c = 5.00;
	
		d = (a+b+c)/2;
		s = sqrt(d*(d-a)*(d-b)*(d-c));

		printf("a = %.2f\n",a);
		printf("b = %.2f\n",b);
		printf("c = %.2f\n\n",c);

		printf("s = %.2f\n",s); 


		return 0;
	}
