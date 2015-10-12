#include<stdio.h>
	int main (void)
{

		int			a;
		int			b;
		int			c;
		int			d;
		int			e;


		printf("Please input three number :\n");
		scanf("%d%d%d",&a,&b,&c);

		if(c>=3000) d=13;
		else d=c/250;


		switch(d)
		{
		case 0: e = 0;break;
		case 1: e = a*b*c;break;
		case 2: e = a*b*c*(1-0.02);break;
		case 3:
		case 4: e = a*b*c*(1-0.05);break;
		case 5:
		case 6:
		case 7:
		case 8: e = a*b*c*(1-0.08);break;
		case 9:
		case 10:
		case 11:
		case 12: e = a*b*c*(1-0.10);break;
		case 13: e = a*b*c*(1-0.15);break;
		}

		printf("The prise is %d\n",e);


		return 0;

	}
