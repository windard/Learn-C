#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

typedef char datatype;
typedef struct node
{
	datatype	 	data;
	struct  node   *next;
}linklist;

linklist * CreatListR1(){
	char 			ch;
	linklist		*head,*s,*r;
	head = (linklist*)malloc(sizeof(linklist));
	r = head;
	printf("请输入顺序表L中的元素，以#结束\n");
	while((ch=getche())!=EOF){
		s = (linklist*)malloc(sizeof(linklist));
		s->data = ch;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}

void Output(linklist *L){
	linklist 	*head;
	head = L;
	head = head->next;
	printf("\n循环表L中的元素为：\n");
	while(head->next!=NULL){
		printf("%3c",head->data );
		head = head->next;
	}
	printf("%3c",head->data );
}


int main(int argc, char const *argv[])
{
	linklist	*L;
	L = CreatListR1();
	Output(L);
	return 0;
}
