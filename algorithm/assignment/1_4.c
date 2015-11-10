#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct node{
	int 			data;
	struct node 	*next;
};

typedef struct table{
	struct node 	 * data;
	struct table  	 * next;
};

node * Create(){
	node 	*head,*L,*P;
	int 	i;
	L = (node*)malloc(sizeof(node));
	head = L;
	while(1){
		scanf("%d",&i);
		if(getchar()=='\n'){
			P = (node*)malloc(sizeof(node));
			P->data = i;
			head->next = P;
			head = P;
			break;
		}else{
			P = (node*)malloc(sizeof(node));
			P->data = i;
			head->next = P;
			head = P;
		}
	}
	head->next = NULL;
	return L;
}

void Output(node *L){
	L = L->next;
	while(L!=NULL){
		printf("%d ",L->data);
		L = L->next;
	}
}

void Backword(node *L){
	node 	*head,*p,*s;
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

int main(void){
	table 	*L,*S,*head;
	int 	num,i;
	L = (table*)malloc(sizeof(table));
	head = L;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		S = (table*)malloc(sizeof(table));
		S->data = Create();
		head->next = S;
		head = S;
	}
	head->next = NULL;
	head = L->next;
	while(head!=NULL){
		Backword(head->data);
		Output(head->data);
		if(head->next!=NULL)
			printf("\n");
		head = head->next;
	}
	// node 	*L;
	// L = Create();
	// Output(L);
	// Backword(L);
	// printf("\n");
	// Output(L);
	return 0;
}
