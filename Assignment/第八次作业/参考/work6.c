#include<stdio.h>
#include<math.h>
double root(int a,int b,int c,double *p1,double *p2)
{
		if(sqrt(b*b-4*a*c)<0)
		{
			return -1;
		}
		else if(sqrt(b*b-4*a*c)==0)
		{
			*p1=*p2=(-b)/(2*a);
			return 0;
		}
		else if(sqrt(b*b-4*a*c)>0)
		{
			*p1=(-b+sqrt(b*b-4*a*c))/(2*a);
			*p2=(-b-sqrt(b*b-4*a*c))/(2*a);
			return 0;
		}
}
int main()
{
	int a,b,c;
	double x1,x2;
	double *p1=&x1;
	double *p2=&x2;
	scanf("%d%d%d",&a,&b,&c);
	if(root(a,b,c,&x1,&x2)==-1)
	{
		printf("no root!\n");
	}
	else 
	{
		printf("x1	=	%lf\n",x1);
		printf("x2	=	%lf\n",x2);
	}
	return 0;
}