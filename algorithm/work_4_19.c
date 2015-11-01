#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

#define MAXSIZE 100

typedef struct 
{
	char ch[MAXSIZE];
	int  len;
}seqstring;

seqstring * DelStr(seqstring *s,int i,int j){
	if(i<=0||i+j>s->len+1||j<0){
		printf("ERROR INPUT\n");
		exit(1);
	}else{
		for (int m = i-1;m+j< s->len; m++)
		{
			s->ch[m] = s->ch[m+j];
		}
	}
	s->len = s->len-j;
	return s;
}

seqstring * Create(){
	int 		i=0;
	char 		ch;
	seqstring   *L;
	L = (seqstring *)malloc(sizeof(seqstring));
	L->len = 0;
	printf("请输入串L中的元素，以#结束\n");
	while((ch=getche())!='#'){
		L ->ch[i++] = ch;
		L ->len ++;
	}
	return L;	
}

void Output(seqstring * L){
	int i;
	printf("\n串L中的元素为：\n");
	for (i = 0; i <= L -> len -1; i ++){
		printf("%3c",L->ch[i] );
	}
}

int main(int argc, char const *argv[])
{
	int a,b;
	seqstring * L;
	L = Create();
	Output(L);		
	printf("\n请输入删除位置：\n");
	scanf("%d",&a);
	printf("\n请输入删除个数：\n");
	scanf("%d",&b);
	L = DelStr(L,a,b);
	Output(L);
	return 0;
}

