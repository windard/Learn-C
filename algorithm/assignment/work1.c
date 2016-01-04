#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node * Create(int num){
	node *head,*P,*L;
//	int		num;
	int		i,j;
	head = (node*)malloc(sizeof(node));
	P = head;
//	scanf("%d",&num);
	for(i=0;i<num;i++){
		L = (node*)malloc(sizeof(node));
		L->data = i+1;
		P->next = L;
		P = L;
	}
	P->next = head->next;
/*	scanf("%d",&num);
	for(i=0;i<num;i++){
		L = (node*)malloc(sizeof(node));
		L->data = i+1;

	}
*/
  return head->next;
}

void Sort(node *head,int ch){
	node *P,*L,*rear;
	int i;
//	P = head;
	rear = (node*)malloc(sizeof(node));
	rear->next = head;
	P = rear;
	do{
		for(i=0;i<ch;i++){
			P = P->next;
		}
		printf("%d  ",P->data);
		L = head;
		while(L->next!=P){
			L = L->next;
		}
		L->next = P->next;
		head = L;
	}while(P!=head);
	printf("\n");
}

void Output(node *P){
	node *head,*L;
	L = P;
	head = P;
/*	while(head!=L){
		printf("%d ",head->data);
		head = head->next;
	}
*/
	do{
		printf("%d ",head->data);
		head = head->next;
	}while(head!=L);
 }


int main(void){
	node *head;
	int		ch,num;
	scanf("%d",&num);
	scanf("%d",&ch);
	if(num<=0||num<ch||ch<=0){
		printf("-1\n");
		return -1;
	}
	head = Create(num);
	Sort(head,ch);
//	Output(head);
	return 0;
}
