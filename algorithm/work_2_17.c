#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define MAXSIZE	 1024

typedef char datatype;
typedef struct 
{
	datatype data[MAXSIZE];
	int 	 last;
}sequenlist;
sequenlist *L;

sequenlist * Create(){
	int 	i = 0;
	char	ch;
	L = (sequenlist*)malloc(sizeof(sequenlist));
	L->last = -1;
	printf("请输入顺序表L中的元素，以#结束\n");
	while((ch=getche())!='#'){
		L ->data[i++] = ch;
		L ->last ++;
	}
	return L;
}

void Output(sequenlist * L){
	int i;
	printf("\n顺序表L中的元素为：\n");
	for (i = 0; i <= L -> last; i ++){
		printf("%3c",L->data[i] );
	}
}

void ToRight(sequenlist * L,int i){
	int j,n;
	for(n=0;n<i;n++){
		for(j=L->last;j>=0;j--){
			L->data[j+1] = L->data[j];
		}
		L->data[0] = L->data[L->last+1];			
	}
}

int main(int argc, char const *argv[])
{
	char ch;
	int i,ret;
	L = Create();
	Output(L);	
	printf("\n请输入右移的位数：\n");
	scanf("%d",&i);
	ToRight(L,i);
	Output(L);
	return 0;
}

