#include<stdio.h>
	int main (void)
{
		int		a,b;
		int		i;
		int		m = 1;

		printf("Please input X,Y\n");
		scanf("%d%d",&a,&b);

		

		for(i = 1;i<=b;i++)
		{
			m=m*a;
		}
		printf("Answer is %d\n",m);

		return 0;
}
