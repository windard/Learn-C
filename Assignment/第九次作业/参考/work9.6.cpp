#include <stdio.h>

char  *del_char(char *str1,char *str2,char  x)
{
	int   i;
	int   j = 0;
	
	if(x>='0' && x<='9')
	{
		for(i=0; *(str1+i)!='\0'; i++)
		{
			if(*(str1+i)< '0' || *(str1+i)>='9')
			{
				str2[j] = *(str1+i) ;
				j++;
			}
		}
	
	}
	

	else
	{
		for(i=0; *(str1+i)!='\0'; i++)
		{
			if(*(str1+i)!=x)
			{
				str2[j] = *(str1+i) ;
				j++;
			}
		}
	}
	str2[j] = '\0';

	return  str2;
}

int main(void)
{
	char    str2[80];
	char    str1[] = "ascasf1234fas563asdfg";
	char    *ps;
	char    x;

	scanf("%c",&x);
	ps  = del_char(str1,str2,x);
	puts(ps);

	return 0;
}