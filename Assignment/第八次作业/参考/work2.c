#include<stdio.h>
#include<math.h>
double  x1,x2;
int root(double a,double b,double c)
{
	double delta;
	delta=b*b-4*a*c;
	if(delta<0)
	{   
		return 0;
	}
	else if(delta==0)
	{
        x1=
		x2=(-b)/(2*a);
		return 1;
	}
	else
	{  
		x1=(-b+sqrt(delta))/(2*a);
        x2=(-b-sqrt(delta))/(2*a);
		return 2;
	}
}
int main()
{   
	double a,b,c;
	scanf("%lf,%lf,%lf",&a,&b,&c);
		if(root(a,b,c)==0)
		{
			printf("没有根\n");
		}
		if(root(a,b,c)==1)
		{
			printf("一个根%f\n",x1);
		}
		if(root(a,b,c)==2)
		{
			printf("两个根%lf  %lf\n",x1,x2);
		}
}
