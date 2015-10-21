#include "stdio.h"
void test(char *a,char *b){
	char c;
	c = *a;
	*a = *b;
	*b = c;
}

int main(int argc, char const *argv[])
{
	char 		a,b;
	char		*c,*d;
	a = 'a';
	b = 'b';
	c = &a;
	d = &b;
	printf("%c\n", a);
	printf("%c\n", b);
	test(c,d);
	printf("%c\n", a);
	printf("%c\n", b);	
	return 0;
}
