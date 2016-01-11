#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int main(int argc, char const *argv[])
{
	FILE 		*fp;
	char		*buf,*ch;
	if ((fp=fopen("URL.txt","r"))==NULL)
	{
	 printf("Cannot open file!\n");
	 exit(0);
	}	
	buf = (char *)malloc(MAX*sizeof(char));
	ch = fgets(buf, MAX, fp);
	while (ch)
	{
		printf("%s",buf);
	    ch = fgets(buf, MAX, fp);  
	}
	fclose(fp);
	return 0;
}
