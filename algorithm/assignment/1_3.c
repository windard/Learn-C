#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct node{
	int 			data;
	struct node * 	next;
};

node * Create(int num){
	node 	*head,*P,*S;
	int 	i;
	head = (node*)malloc(sizeof(node));
	P = head;
	for(i=0;i<num;i++){
		S = (node*)malloc(sizeof(node));
		scanf("%d",&S->data);
		P->next = S;
		P = S;
	}
	P->next = NULL;
	return head;
}

void Output(node * L){
	node *head;
	head = L->next;
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;
	}
}

node * Insert(node * L,int num){
	node 	*S,*head;
	head = L;
	while(head->next!=NULL){
		head = head->next;
	}
	S = (node*)malloc(sizeof(node));
	S->data = num;
	head->next = S;
	head = S;
	head->next = NULL;
	return L;
}

node * Sort(node * L){
	node *head,*first;
	int  		temp,flag=1;
	while(flag){
		head = L->next;
		first = head->next;
		flag = 0;
		while(first!=NULL){
			if(head->data>first->data){
				temp = head->data;
				head->data = first->data;
				first->data = temp;
				flag = 1;
			}
			head = head->next;
			first = first->next;
		}

	}
	return L;

}

int main(void){
	node 		*L;
	int 		num,intnum;
	scanf("%d %d",&num,&intnum);
	L = Create(num);
	L = Insert(L,intnum);
	L = Sort(L);
	Output(L);
	return 0;
}

