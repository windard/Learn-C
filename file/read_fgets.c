#include <stdio.h>
#include <stdlib.h> // for exit

#define MAX 1024

int main(int argc, char const *argv[])
{
	FILE 		*fp;
	char		*buf,*ch;

	if ((fp=fopen("read_file.c","r"))==NULL)
	{
	 printf("Cannot open file!\n");
	 exit(0);
	}	
	buf = (char *)malloc(MAX*sizeof(char));
	ch = fgets(buf, MAX, fp);
	while (ch) // or ch != NULL
	{
		printf("%s",buf);
	    ch = fgets(buf, MAX, fp);  
	}
	fclose(fp);
	return 0;
}
