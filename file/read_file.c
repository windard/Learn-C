#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024

int main(int argc, char const *argv[])
{
	char 		buffer[MAX_FILE_SIZE];
	int 		i;
	FILE 		*fp;

	if ((fp=fopen("read.c","r"))==NULL)
	{
	 printf("Cannot open file!\n");
	 exit(0);
	}

	for (i = 0; i < MAX_FILE_SIZE; ++i)
	{
	    int c = getc(fp);

	    if (c == EOF)
	    {
	        buffer[i] = 0x00;
	        break;
	    }

	    buffer[i] = c;
	}

	printf("%s\n", buffer);
}
