#include<stdio.h>
void main()
{
	int i_var;
	double d_var;
	char ch_var='a';
	int    *pi;
	double *pd;
	char  *pc;
	pi=&i_var;
	pd=&d_var;
	pc=&ch_var;
	printf("i_var   = %#d\n d_var   = %#lf\n ch_var   = %#c\n pi   = %p\n pd   = %p\n pc   = %p\n",i_var,d_var,ch_var,pi,pd,pc);
	printf("&i_var  =%p\n &d_var   = %p\n  &ch_var   =%p\n &pi   =%p\n &pd     =%p\n &pc    =%p\n",pi,pd,pc,&pi,&pd,&pc);
	*pi=2;
	*pd=3.0;
	*pc='b';
    printf("i_var   = %#d\n d_var   = %#lf\n ch_var   = %#c\n pi   = %p\n pd   = %p\n pc   = %p\n",i_var,d_var,ch_var,pi,pd,pc);
}