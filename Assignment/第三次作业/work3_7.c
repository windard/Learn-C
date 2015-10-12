# include <stdio.h>

int main (void)
{
		int			a;
		int			b;
		int			c;
		int			d;

		printf("please input two number:\n");
		scanf("%d%d",&a,&b);
		printf("your input is: %4d%4d\n",a,b);

		if(b!=0)

		{	c = a/b;
			d = a%b;
			printf("%d divided by %d is %d and the reminder is %d \n",a,b,c,d);
		}
		else
		{
			printf("Error: zero divisor\n");
		}
		return 0;
}