#include<stdio.h>
int main (void)
{
	int		i,a,b,c,n=0;
	scanf("%d%d%d",&a,&b,&c);
	for(i=10;i<101;i++)
		if(i%3==a)
			if(i%5==b)
				if(i%7==c)
				{
					printf("%d\n",i);
					n=1;
				}
	if(n);
	else
		printf("No answer\n");
	return 0;
}