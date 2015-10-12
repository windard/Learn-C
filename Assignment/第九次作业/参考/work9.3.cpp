#include <stdio.h>

void move_max_char(char * str)
{
	int   i;
	int   max_loc;
	char  max;
	char  temp;
	
	max = *str;
	for(i=0;*(str+i)!='\0';i++)
	{
		
		if(max < *(str+i))
		{
			max = *(str+i);
			max_loc = i;
		}
	}

	while(*(str+max_loc+1)!='\0')
	{
		temp = *(str+max_loc);
		*(str+max_loc) = *(str+max_loc+1);
		*(str+max_loc+1) = temp;
		max_loc++;

	}

	
	/*for(i=0; *(max_loc+i)!='\0';i++)
	{
		temp = *(max_loc+i);
		*(max_loc+i)= *(max_loc+i+1);
		*(max_loc+1+i) = temp;
	}*/
}

int main(void)
{
	char   str[] = "shyab";

	printf("The old string is\n");
	puts(str);
	
	move_max_char(str);
	
	printf("The new is\n");
	puts(str);

	return 0;

}