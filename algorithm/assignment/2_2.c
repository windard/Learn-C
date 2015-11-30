#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
	int 	data;
	struct node *next;
};

node * Create(){
	int 	ch;
	int		num;
	node * L,*head,*P;
	head = (node*)malloc(sizeof(node));
	L = head;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		P = (node*)malloc(sizeof(node));
		scanf("%d",&P->data);
		L->next = P;
		L=P;
	}
	L->next = NULL;

	return head;
}

void Sort(node *L){
	node 	*S1,*S2;
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

void Output(node *L){
	node 	*head;
	head = L->next;
	while(head!=NULL){
		if(head->next!=NULL)
			printf("%d ",head->data);
		else{
			printf("%d",head->data);
		}
		head = head->next;
	}

}

int main(void){
	node 		*L;
	L = Create();
	Sort(L);
	Output(L);
	
	return 0;	
}


