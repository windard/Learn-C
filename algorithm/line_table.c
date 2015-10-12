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

int Inset(sequenlist *L,int x,int i){
	int 	j;
	if((L->last)>=MAXSIZE-1){
		printf("overflow\n");
		return 0;
	}else if((i<1)||(i>(L->last)+2)){
			printf("error\n");
			return 0;
		
	}else{
		for(j=L->last;j>=i-1;j--){
			L->data[j+1] = L->data[j];
		}
		L->data[i-1] = x;
		L->last = L->last+1;
		return 1;
	}
}

void Output(sequenlist * L){
	int i;
	printf("\n顺序表L中的元素为：\n");
	for (i = 0; i <= L -> last; i ++){
		printf("%3c",L->data[i] );
	}
}

int Delete(sequenlist *L,int i){
	int j;
	if((i<1)||(i>L->last+1)){
		printf("error\n");
		return 0;
	}else{
		for(j=i;j<=L->last;j++){
			L->data[j-1] = L->data[j];
		}
		L->last --;
		return 1;
	}
}

int main(int argc, char const *argv[])
{
	char ch;
	int i,ret;
	L = Create();
	Output(L);	
	// printf("\n请输入插入字符\n");
	// scanf("%c",&ch);
	// printf("\n请输入插入位置\n");
	// scanf("%d",&i);
	// ret = Inset(L,ch,i);
	// if(ret)
	// 	Output(L);
	printf("\n请输入删除位置\n");
	scanf("%d",&i);
	ret = Delete(L,i);
	if(ret)
		Output(L);	
	return 0;
}

