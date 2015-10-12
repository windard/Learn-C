#include<stdio.h>

char * my_strcpy(char *pdst,char * psrc);

int main (void)
{
	char		src[]="hello,world";
	char		dst[80];

	my_strcpy(dst,src);

	printf("src=%s\n",src
		);
	printf("dst=%s\n",dst);

	return 0;

}

char * my_strcpy(char *pdst,char * psrc)
{

	for(;*psrc!='\0';psrc++,pdst++)
	{
		*pdst=*psrc;
	}

	*pdst='\0';

	return;

}
