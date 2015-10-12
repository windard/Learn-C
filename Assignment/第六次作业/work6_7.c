#include<stdio.h>
	int main (void)
{
		char			str[] ={"I looove you!"};
		int				i;



		printf("Old	string is:\n");
		for(i=0;str[i]!='\0';i++)
			printf("%c",str[i]);
			printf("\n");
		printf("New string is :\n");

		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]!='o')
				printf("%c",str[i]);
		}
		printf("\n");

		return 0;
	}
