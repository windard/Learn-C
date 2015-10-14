#include "conio.h"
int main(int argc, char const *argv[])
{
	char 	a,b;
	a = getche();
	b = getche();
	if(a>b){
		printf("%c\n",a );
	}else{
		printf("%c\n",b );
	}
	return 0;
}