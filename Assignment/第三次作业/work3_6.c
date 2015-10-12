#include <stdio.h>

	int main (void)

	{

		char	a;
		char	b;
	



		printf("please input a character:\n");
		a = getchar();
		
		printf("your input:    %c\n",a);
			b = a -  32;
		printf("output:        %c\n",b);
		return 0;
	}