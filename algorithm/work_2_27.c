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
	linklist *head,*P1,*P2,*S1,*S2;
	P1 = L1->next;
	S1 = P1;
	P2 = L2->next;
	S2 = P2;
	head = L1;
	while((head!=P1)&&(head!=P2)){
		while((S1->next!=NULL)&&(S1->next!=head)){
			S1 = S1->next;
		}
		while((S2->next!=NULL)&&(S2->next!=head)){
			S2 = S2->next;
		}	
		if(S1->data>=S2->data){
			head->next = S1;
			head = S1;
			S1 = P1;
			S2->next = NULL;
		}else{
			head->next = S2;
			head = S2;
			S2 = P2;
			S1->next = NULL;
		}
	}
	if(head == P1){
		head ->next = S2;
		head = S2;
		S1 = S2;				
		while(head!=P2){
			while((S2->next!=NULL)&&(S2->next!=head)){
				S2 = S2->next;
			}	
			if(S1->data>=S2->data){
				head->next = S2;
				head = S2;
				S1 = S2;
				S2 = P2;
			}else{

			}		
		}
	}else{
		head ->next = S1;
		head = S1;
		S2 = S1;			
		while(head!=P1){			
			while((S1->next!=NULL)&&(S1->next!=head)){
				S1 = S1->next;
			}	
			if(S1->data>S2->data){
			
			}else{
				head->next = S1;
				head = S1;
				S2 = S1;
				S1 = P1;	
			}				
		}		
	}
	head->next = NULL;
	return L1;
}

int main(int argc, char const *argv[])
{
	linklist	*La,*Lb,*L;
	La = CreatListR1();
	Lb = CreatListR1();
	Output(La);
	Output(Lb);
	L = Union(La,Lb);
	Output(L);
	return 0;
}
