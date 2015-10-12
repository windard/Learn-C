#include<stdio.h>
#include"f1.H"
int main(void)
{
	double a,b,c;
	double s;
	scanf("%lf,%lf,%lf",&a,&b,&c);
	if(tri_area(a,b,c)==-1)
	{
		printf("无法构成三角形\n");
	}
	else
	{ 
		s=tri_area(a,b,c);
		printf("%lf\n",s);
	}
	return 0;
}
