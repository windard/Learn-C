#include <stdio.h>

char * my_strcat(char * pdst,char * psrc)
{
	int i=0;

	
	while(*(pdst+i)!='\0')
		i++;
	
	pdst = pdst+i;

	while(*pdst++=*psrc++);
	


	
	
	return pdst;
}

int main(void)
{
	char    dst[80] = "Hello";
    char    src[] = " world";
    

    printf("dst = %s\n",dst);
    printf("src = %s\n",src);

    my_strcat(dst,src);

    printf("combined string = %s\n",dst);
    return 0;
}
