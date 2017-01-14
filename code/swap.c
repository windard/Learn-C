#include "stdio.h"

void swap_wrong(char *a, char *b){
	char *c;
	c = a;
	a = b;
	b = c;
}

void swap_right(char *a, char *b){
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
	printf("original   : %c %c\n", a, b);
	swap_wrong(c, d);
	printf("swap_wrong : %c %c\n", *c, *d);
	swap_right(c, d);
	printf("swap_right : %c %c\n", *c, *d);
	return 0;
}