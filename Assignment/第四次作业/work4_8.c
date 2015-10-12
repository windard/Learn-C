# include<stdio.h>

int main (void)
{
	int num ;
	int k = 1;


	printf("Please input a number:\n");
	scanf("%d",&num);

	do
	{
	

	k = k * (num %10);
	num = num / 10; 
	}
	while(num!=0);

	printf("%d\n",k);

	return 0;
}

