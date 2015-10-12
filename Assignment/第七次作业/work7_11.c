#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void)
{
	
	double		pi;
	int			cnt;
	
	double pi_monte_carlo(int cnt);
	int is_in_circle(double x,double y);
	
	printf("Please input a number:\n");
	scanf("%d",&cnt);
	
	pi=pi_monte_carlo(cnt);
	printf("%f",pi);
	
	return 0;
}
		int is_in_circle (double x,double y)
	{
		
		double			x;
		double			y;

 		int				m=0;

	
		
		if(x*x+y*y<=1)
				m=1;
			
			return (m);	
		
	}
	
	
	double pi_monte_carlo(int cnt)
	{
		double		x;
		double		y;
		double		pi;
		int			i;
		int			m=0;
		int			n=0;
		
		int is_in_circle (double x,double y);
		
		
		srand(time(NULL));

		x=(double)rand()/RAND_MAX;
		y=(double)rand()/RAND_MAX;
		
		for(i=1;i<=cnt;i++)
		{
			if(is_in_circle(x,y))
				m++;
			else
				n++;	
		}
			pi=(m/(m+n))*4;
			return(pi);	
		
	}
	
	
	
	
	
	
	
	
	
	
	
