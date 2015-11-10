#include "stdio.h"
#include "stdlib.h"

int main(void){
	int 		i,sum=0,cnt=0;
	double 		ans;
	while(1)
	{
		scanf("%d", &i );
		if ( getchar()=='\n')
		{
			sum += i ;
			cnt++ ;			
			printf("%.3lf\n", (double)sum/cnt );
			break;
		}
		else
		{
		    sum += i ;
		    cnt++ ;
		}
	}	
	return 0;	
}