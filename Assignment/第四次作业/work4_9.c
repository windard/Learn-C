#include <stdio.h>
	int main (void) 
{

	
		int		i;

		for(i=1900;i<=2013;i++)
		{
			if((i%4==0&&i%100!=0)||i%400==0)
			printf("%10d",i);
		
	
		}
		return 0;
	}
