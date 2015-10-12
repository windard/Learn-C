#include<stdio.h>
	int main (void)
{
		char			str1[80];
		char			str2[80];
		int				i;
		int				j;



		printf("Input 1st str:\n");
		gets(str1);
		printf("Input 2nd str\n");
		gets(str2);

		printf("\n");

		printf("The merged str is :\n\n");

		for(i=0;str1[i]!='\0';i++)
			printf("%c",str1[i]);
		for(j=0;str2[j]!='\0';j++)
			printf("%c",str2[j]);

		printf("\n");





		return 0;
	}

