#include "stdio.h"
#include "string.h"
#define MAXSIZE 1000 + 10
int a[MAXSIZE];
int main(int argc, char const *argv[])
{
	int 	i,j,flag,m,n,first=1;
	memset(a,0,sizeof(a));
	scanf("%d%d",&i,&j);
	for(m=1;m<=j;m++){
		for(n=1;n<=i;n++){
			if(n%m==0){
				a[n]=!a[n];
			}
		}
	}
	for(m=1;m<=i;m++){
		if(a[m]){
			if(first){
				first=0;
			}else{
				printf(" ");
			}
			printf("%d",m);
		}
	}
	return 0;
}
