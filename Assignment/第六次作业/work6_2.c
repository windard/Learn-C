#include<stdio.h>
	int main (void)
{
		int			arr[] = {1,3,13,2,7,9,53};
		int			size;
		int			i;
		int			m;
		int			k;
		int			j = 0;
		


		size = sizeof(arr)/sizeof(arr[1]);
		printf("The arr is :\n");
		for(i=0;i<size;i++)
			printf("%4d",arr[i]);
		printf("\n");
		printf("The primes are: \n");
		
		for(i=1;i<size;i++)
		{	
			k = 0;
			for(m=2;m<arr[i];m++)
			{
				if(arr[i]%m==0)
				{	
					k =1;
					break;
				}

				
			}

		
		
				if(k == 0)
				{
					printf("%4d",arr[i]);
					j++;
				}
				
		}
		printf("\n");
		printf("Total %d prime in this array\n",j);
		return 0;
	}




 
