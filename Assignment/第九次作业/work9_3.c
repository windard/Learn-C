/*
#include<stdio.h>

void move_max_char(char *pstr);

int main (void)
{
	char		str[]="chyab";

	move_max_char(str);

	puts(str);

	return 0;
}

void move_max_char(char *pstr)
{
	char		x;
	char		*str;
	int			max_loc;
	int			i;
	char		temp;
*/
  /*

	str=pstr;

	x=*str;

	for(;*str!='\0';str++)
	{
		if(x<)
	}
*/
/*	str=pstr;

	x=*str;

	for(i=0;*str!='\0';str++)
	{
		i++;
		if(x<*str)
		{
			x=*str;
			max_loc=i;
		}
	}

	for(i=max_loc;*(pstr+i)!='\0';i++)
	{
		temp=*(pstr+i);
		*(pstr+i)=*(pstr+i+1);
		*(pstr+i+1)=temp;
	}



	return;
}
*/


#include<stdio.h>

void move (char *arr);

int main (void)
{

	char			arr[]="chyab";
//	int				i;

	move(arr);

	puts(arr);

	return 0;

}

void move (char *arr)
{
	int			i;
	int			j;
	char		*str;
	char		temp;

	str=arr;


	for(i=0;str!='\0';i++)
	{
		if(*str<*(str++))
		{
			temp=*str;
			*str=*str++;
			*str++=temp;
		}
	}

	puts(str);

	return;
}