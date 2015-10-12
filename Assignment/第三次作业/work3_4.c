#include<stdio.h>

int main (void)
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;


	printf("please input a number \n");
	scanf("%d",&a);
	printf("you input is: %4d\n",a);
	
		b = a/1000;
		c = (a%1000)/100;
		d = ((a%1000)%100)/10;
		e = (((a%1000)%100)%10)/1;
		printf("%4d%4d%4d%4d\n",e,d,c,b);

	return 0;
}

