#include<stdio.h>

char *my_strcat(char *pdst,char *psrc);

int main (void)
{

	char		dst[]="hello";
	char		src[80]="world";

	printf("dst=%s\n",dst);
	printf("src=%s\n",src);

	my_strcat(dst,src);

	printf("combined string=%s",src);

	return 0;
}

char *my_strcat(char *pdst,char *psrc)
{
	char			str[80];
	int				i;
	
	for(i=0;*pdst!='\0';i++,pdst++)
	{
		str[i]=*pdst;
	}

	for(;*psrc!='\0';i++,psrc++)
	{
		str[i]=*psrc;
	}
	
	
	for(i=0;str[i]!='\0';i++,psrc++)
		*psrc=str[i];

	printf("str=%s",str);

	return;
}