#include<stdio.h>
#include<math.h>
double tri_area(double a,double b,double c)
{
	int s;
	int l;
	l=(a+b+c)/2;
	if((a+b)>c&&(b+c)>a&&(a+c)>b)
    {
		s=sqrt(l*(l-a)*(l-b)*(l-c));
		return s;
	}
	else
	{
		return -1;
	}
}