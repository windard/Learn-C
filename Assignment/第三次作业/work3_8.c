#include <stdio.h>

	int main (void)
	{
		char		x;
		char		y;

		printf("please input a char :\n");
		scanf("%c",&x);


		printf("your input : %c\n",x);


		if(x>90)
		{
			y = x - 32;
			printf("output : %c\n",y);

		}
		else 
		{	printf("Error:          the input is not a little character\n");

		}

	return 0;

	}
