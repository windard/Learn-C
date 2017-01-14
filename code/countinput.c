#include "stdio.h"
#include "conio.h"

int main(int argc, char const *argv[])
{
	char 	ch;
	int 	len = 0;
	puts("Type in a sentence, then press <ENTER>");
	while((ch=getch()) != '\r'){
		putchar(ch);
		len++;
	}
	printf("\nSentence is %d characters longs.\n", len);
	return 0;
}