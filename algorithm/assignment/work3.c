#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
	int data;
	struct node *lchild,*rchild,*parent;
	struct node *next;
}node;

#define EPS 1e-5

node* Create(int num){
	node *head,*P,*L;
	int		i,j,ch;
	head = (node*)malloc(sizeof(node));
	P = head;
	for(i=0;i<num;i++){
		scanf("%d",&ch);
		L = (node*)malloc(sizeof(node));
		L->data = ch;
		L->parent  = NULL;
		L->lchild  = NULL;
		L->rchild  = NULL;
		P->next = L;
		P = L;
	}
	P->next = NULL;
	return head;
}

void Output(node *head){
	node *P;
	P = head->next;
	while(P!=NULL){
		printf("%d ",P->data);
		P = P->next;
	}
}

void Haffman(node *H,int num){
	node	*P,*L,*head,*p1,*p2;
	int		i,j;
	int		small1,small2;
	for(i=0;i<num-1;i++){
		head = H->next;
		p1 = p2 = NULL;
		small1 = small2 = 10000;
		while(head!=NULL){
			if(head->parent == NULL){
				if(head->data - small1 < EPS){
					small2 = small1;
					small1 = head->data;
					p2 = p1;
					p1 = head;
				}else if(head->data -small2 < EPS){
					small2 = head->data;
					p2 = head; 
				}
			}
			head = head->next;
		}
		L = (node*)malloc(sizeof(node));
		p1->parent = L;
		p2->parent = L;
		L->lchild = p1;
		L->rchild = p2;
		L->parent = NULL;
		L->data = p1->data + p2->data;
		head = H->next ;
		while(head->next!=NULL){
			head = head->next;
		}
		head->next = L;
		L->next = NULL;
	}
}

int Counter(node *head,int deep){
	int  i,j;
	static int  num=0;
	if(head->lchild == NULL && head->rchild == NULL){
		num = num + deep*(head->data);
	}else{
		i = Counter(head->lchild ,deep+1);
		j = Counter(head->rchild ,deep+1);
	}
	return num;
}

int main(void){
	int num;
	int result;
	node *head;
	node *last;
	scanf("%d",&num);
	head = Create(num);
	Haffman(head,num);
	last = head->next;
	while(last->next!=NULL){
		last = last->next;
	}
	result = Counter(last,0);
	printf("\n %d \n",result);
	return 0;
}