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
	printf("\n请输入顺序表L中的元素，以#结束\n");	
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

linklist * Union(linklist * L1,linklist * L2){
	linklist *head,*S1,*S2;
	S1 = L1->next;
	S2 = L2->next;
	head = L1;
	while((S1!=NULL)&&(S2!=NULL)){
		if(S1->data <= S2->data){
			head->next = S1;
			head = S1;
			S1 = S1->next;
		}else{
			head->next = S2;
			head = S2;
			S2 = S2->next; 
		}		
	}
	if(S1 == NULL){
		head->next =  S2;		
	}else{
		head->next = S1;
	}
	return L1;
}

void Backword(linklist * L){
	linklist 	*head,*p,*s;
	p = L->next;
	head = L;
	while(head->next!=NULL){
		head = head->next;
	}
	s = p;
	L->next = head;
	while(head!=p){
		while(s->next!=head){
			s = s->next;
		}
		head->next = s;
		head = s;
		s = p;	
	}
	head->next = NULL;
}

int main(int argc, char const *argv[])
{
	linklist	*La,*Lb,*L;
	La = CreatListR1();
	Lb = CreatListR1();
	Output(La);
	Output(Lb);
	L = Union(La,Lb);
	Backword(L);
	Output(L);
	return 0;
}
