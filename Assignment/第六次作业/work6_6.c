#include<stdio.h>
	int main (void)
	{
		char			str[80];
		int				i;

		

		
		printf("Input a string:\n");
		gets(str);
		
		printf("Length of [");
		for(i=0;str[i]!='\0';i++)
		{
			printf("%c",str[i]);
		
			
			
		}
		printf("] is %4d",i);

		
		
		return 0;
		
		
		
		
		
		
		
		
		
		
		
	}
