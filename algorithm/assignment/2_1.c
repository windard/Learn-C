#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

typedef struct node{
	int				data;
	struct node *   next;
};

typedef struct table{
	int 		data[1024];
	int 		num;

};

node * Create(){
	int		ch;
	node	*L,*head,*P;
	P = (node*)malloc(sizeof(node));
	head=P;
	for(int i=0;i<3;i++){
		L =(node*)malloc(sizeof(node));
		scanf("%d",&L->data);
		P->next = L;
		P = L;
		}
	P->next = NULL;
	return head;
}

int Calcu(int L){
	table 		*head;
	int 		ch;
	int 		last;
	int 		i=0,j=0;
	int 		result=0;
	head = (table*)malloc(sizeof(table));
	ch = L;
//	printf("\nTHERE IS CH %d\n",ch);
	while(ch!=0){
		last = ch%2;
//		printf("\n%d\n",last);
		head->data[i]=last;
		ch = ch/2;
//		printf("\n%d\n",ch);
		i++;
	}
	i--;
	while(i>=0){
		result = head->data[i]+result;
//		printf("\nThis is RESULT%d\n",result);
		result = result*10;
		i--;
	}
	return result/10;

}

void Output(node*L){
	int		ch;
	int 	result;
	node	*head;
	head = L->next;
	while(head!=NULL){
		result = Calcu(head->data);
		printf("%d ",result);
		head = head->next;
		}
	}

int main(void){
	node *L;
	L = Create();
	Output(L);
	return 0;
	}
