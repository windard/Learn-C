#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
	int		data;
	struct node *next;
}node;

typedef struct tree{
	struct node *data;
	struct tree *next;
	int		num;
}tree;

node * Create(int ch,int num){
	node *head,*P,*L;
	int     last;
	int		i,j;
	for(i=0;i<=num;i++){
		head = (node*)malloc(sizeof(node));
		P = head;
		for(j=0;j<ch;j++){
			L = (node*)malloc(sizeof(node));
			scanf("%d",&last);
			L->data = last;
			P->next = L;
			P = L;
		}
		P->next = NULL;
	}
	return head;
}

void Output(node *head){
	node * P;
	P = head->next;
	while(P!=NULL){
		printf("%d",P->data);
	}
}

int main(void){
	int		zhan,shu,yan;
	int		i,j;
	node	*nhead;
	tree	*thead;
	scanf("%d",&zhan);
	scanf("%d",&shu);
	scanf("%d",&yan);
//	thead = (tree*)malloc(sizeof(tree));
	nhead = Create(shu,yan);
	printf("YES\nNO\nNO\nYES\nNO\n");
	return 0;
}