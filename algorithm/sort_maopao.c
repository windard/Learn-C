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
	while((ch=getche())!='#'){
		s = (linklist*)malloc(sizeof(linklist));
		s->data = ch;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}

void Sort(linklist *L){
	linklist 	*S1,*S2;
	int 		flag;
	S1 = L;
	S2 = L->next;
	flag = 1;
	while(flag){
		flag = 0;
		while(S2->next!=NULL){
			if(S1->next->data > S2->next->data){
				flag = 1;
				S1->next = S2->next;
				S1 = S1->next;
				S2->next = S1->next;
				S1->next = S2;		
			}else{
				S2 = S2->next;
				S1 = S1->next;  
			}
		}
		S1 = L;
		S2 = L->next;		
	}
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
	Sort(L);
	Output(L);
	return 0;
}
