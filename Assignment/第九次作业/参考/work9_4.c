#include <stdio.h>

char * my_strcpy(char * psrc,char * pdst)
{


	while(*pdst++ = *psrc++);


	return pdst;
}

int main(void)
{
    char src[] = "Hello world";
    char dst[80];

    my_strcpy(src,dst);
    printf("src = %s\n",src);
    printf("dst = %s\n",dst);
    return 0;

}
