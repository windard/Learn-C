#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 24

typedef struct node{
	char  		name[MAXSIZE];
	int 		id;
	char 		sex;
	int 		last;
	struct	node * 		next;
};


node * Create(){
	node  		*L,*head,*P;
	int 		del;
	P = (node*)malloc(sizeof(node));
	head = P;
	while(1){
		L = (node*)malloc(sizeof(node));	
		scanf("%s",&L->name);
		if(L->name[0]=='#')
			break;
		scanf("%d %c",&L->id,&L->sex);
		P->next = L;
		P=L;		
	}
	P->next= NULL;
	return head;
}

int Delete(node * L){
	int  del;
	node *head,*P,*t;
	head = L;
	scanf("%d",&del);
	P=head->next;
	while(P!=NULL){
		if(P->id==del){
			t = head;
			while(t->next!=P){
				t = t->next;
			}
			t->next = P->next;
			free(P);
			break;			
		}else{
			P=P->next;
		}
	}
	if(P==NULL){
		return 0;
	}else{
		return 1;
	}
}


void Output(node *L){
	node 	*head;
	head = L;
	head = head->next;
	while(head!=NULL){
		printf("%s %d %c\n",head->name,head->id,head->sex);
		head = head->next;
	}
}

int main(void){
	char 		str[20];
	int  		id,a;
	node 	* L;
	L = Create();
	a = Delete(L);
	if(!a){
		printf("No\n");
	}else{
		Output(L);
	}
	return 0;
}



