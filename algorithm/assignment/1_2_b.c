#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct node{
	int 			a,b;
	struct node * 	next;
};

node * Create(){
	node * L,*head,*P;
	int 	i;
	L = (node * )malloc(sizeof(node));
	scanf("%d",&L->a);
	head = L;
	P = L;
	for(i=0;i<head->a;i++){
		L = (node*)malloc(sizeof(node));
		scanf("%d %d",&L->a,&L->b);
		P->next = L;
		P = L;
	}
	P->next = NULL;
	return head;
}

void Output(node *L){
	int 	i;
	node    *head;
	head = L->next;
	printf("%d ",L->a);
	for(i=0;i<L->a;i++){
		printf("%d %d ",head->a,head->b );
		head = head->next;
	}	
}

node * Plus(node * L1,node * L2){
	node 			*head,*P,*p1,*p2,*S;
	int 			sum;
	P = (node*)malloc(sizeof(node));
	P->a = 0;
	head = P;
	p1 = L1->next;
	p2 = L2->next;
	while(p1!=NULL&&p2!=NULL){
		if(p1->b==p2->b){
			S = (node*)malloc(sizeof(node));
			sum = p1->a + p2->a;
			if(sum){
				S->a = sum;
				S->b = p1->b;
				head->next = S;
				head = S;
				P->a++;			
			}
			p1 = p1->next;
			p2 = p2->next;
		}else if(p1->b>p2->b){
			S = (node*)malloc(sizeof(node));
			S->a = p1->a;
			S->b = p1->b;
			head->next = S;
			head = S;
			P->a++;
			p1 = p1->next;
		}else{
			S = (node*)malloc(sizeof(node));
			S->a = p2->a;
			S->b = p2->b;
			head->next = S;
			head = S;
			P->a++;
			p2 = p2->next;
		}
	}
	if(p1==NULL){
		while(p2!=NULL){
			S = (node*)malloc(sizeof(node));
			S->a = p2->a;
			S->b = p2->b;
			head->next = S;
			head = S;
			P->a++;
			p2 = p2->next;
		}
	}else{
		while(p1!=NULL){
			S = (node*)malloc(sizeof(node));
			S->a = p1->a;
			S->b = p1->b;
			head->next = S;
			head = S;
			P->a++;
			p1 = p1->next;
		}
	}
	return P;
}

node * Minus(node * L1,node * L2){
	node 			*head,*P,*p1,*p2,*S;
	int 			sum;
	P = (node*)malloc(sizeof(node));
	P->a = 0;
	head = P;
	p1 = L1->next;
	p2 = L2->next;
	while(p1!=NULL&&p2!=NULL){
		if(p1->b==p2->b){
			S = (node*)malloc(sizeof(node));
			sum = p1->a - p2->a;
			if(sum){
				S->a = sum;
				S->b = p1->b;
				head->next = S;
				head = S;
				P->a++;			
			}
			p1 = p1->next;
			p2 = p2->next;
		}else if(p1->b>p2->b){
			S = (node*)malloc(sizeof(node));
			S->a = p1->a;
			S->b = p1->b;
			head->next = S;
			head = S;
			P->a++;
			p1 = p1->next;
		}else{
			S = (node*)malloc(sizeof(node));
			S->a = -p2->a;
			S->b = p2->b;
			head->next = S;
			head = S;
			P->a++;
			p2 = p2->next;
		}
	}
	if(p1==NULL){
		while(p2!=NULL){
			S = (node*)malloc(sizeof(node));
			S->a = p2->a;
			S->b = p2->b;
			head->next = S;
			head = S;
			P->a++;
			p2 = p2->next;
		}
	}else{
		while(p1!=NULL){
			S = (node*)malloc(sizeof(node));
			S->a = p1->a;
			S->b = p1->b;
			head->next = S;
			head = S;
			P->a++;
			p1 = p1->next;
		}
	}
	return P;
}

int main(void){
	node *L1,*L2,*L3,*L4;
	L1 = Create();
	L2 = Create();
	L3 = Plus(L1,L2);
	L4 = Minus(L1,L2);
	Output(L3);
	printf("\n");
	Output(L4);
	return 0;
}
