#include<stdio.h>
int factor(int n)
{
	int i;
	int a=1;
	for(i=1;i<=n;i++)
	{ 
	  a=i*a;
	}
	return a;
}
double sum_factor(int n)
{
	double a=1;
    double b;
	double c=0;
	if(n=0)
	{
		c=1;
	}
	else
	{
	   if(factor(n))
	   {
		   b=1/a;
		   c=c+b;
	   }
	}
	return c;
}
int main(void)
{
	int n;
	printf("please input n(0 to exit)\n");
	scanf("%d",&n);
	if(sum_factor(n))
	printf("%f",sum_factor(n));
}
	