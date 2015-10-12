#include <stdio.h>
int main (void)
{

	char		arr[80];
	int			i;
	int			size;


	printf("Please input chararr:\n");
	gets(arr);

	size=strlen(arr);

	printf("Your input is:\n");

	for(i=0;i<size;i++)
		printf("%c",arr[i]);

	printf("\n");

	printf("The answer is:\n");

	for(i=size-1;i>=0;i--)
		printf("%c",arr[i]);

	printf("\n");	


	return 0;

}