#include<stdio.h>
#include<math.h>

	int main (void)
{	

		float		a,b,c;
		float		l,s;

		printf("Input a,b,c\n");
		scanf("%f%f%f",&a,&b,&c);

		if(a<=0||b<=0||c<=0)
		{
			printf("Illegal input!\n");
		
		}
		if(a+b>c&&a+c>b&&b+c>a)
		{
			l=(a+b+c)/2;
			s=sqrt(l*(l-a)*(l-b)*(l-c));
			printf("area s=%.2f\n",s);
		}
		else
			printf("your input is wrong\n");

		return 0;
	}
		
