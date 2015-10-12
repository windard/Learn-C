#include<stdio.h>
#include<time.h>
int main ()
{
	time_t	t;
	time(&t);
	printf("%s",ctime(&t));
	getchar();
	return 0;
}
