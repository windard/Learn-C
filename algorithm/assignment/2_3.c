#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int 	data;
	struct node * next;
};

typedef struct table{
	int 	data[1024];
	int 	num;
};

typedef struct all{
	struct  node* data[1024];
	int  	num;
	int 	last;
};

all *Create(){
	int 		inum,jnum,knum,i,k;
	scanf("%d",&inum);
	scanf("%d",&jnum);	
	scanf("%d",&knum);
	node *L,*head,*P;
	all * M;
	M = (all*)malloc(sizeof(all));
	for(k=0;k<knum+1;k++){
		head = (node*)malloc(sizeof(node));
		L = head;
		for (i=0;i<jnum;i++){
			P = (node*)malloc(sizeof(node));
			scanf("%d",&P->data);
			L->next = P;
			L = L->next;
		}
		L->next = NULL;
		M->data[k]=head;
	}
	M->num = inum;
	M->last = k;
	return M;
}

void Calcu(all  *L){
	all * head;
	node 	*p1,*p2;
	int 		flag;
	head = L;
	flag = 1;
	int 	i,j,k;
	// printf("%d",head->num);
	// printf("%d",head->last);
	table *P,*M;
	for(i=1;i<head->last;i++){
		
		k = -1;
		p1 = head->data[0]->next;
		P = (table*)malloc(sizeof(table));
		p2 = head->data[i]->next;
		while(p1!=NULL){
			printf("55555555555555555555555555555555\n");
			if(p1->data==p2->data){
				p1 = p1->next;
				p2 = p2->next;	
			}else{
				if(k!=-1){
					if(P->data[k]==p2->data){
						p2 = p2->next;					
						k--;
					}else{
						k++;	
						P->data[k]=p1->data;
						p1 = p1->next;
						
					}
				}else{
					k++;
					P->data[k] = p1->data;
					p1 = p1->next;
					
				}
			}
			if(k>=5){
				printf("%dNO\n",i);
				flag = 0;
				break;
			}
		}
		if(flag){
			while(p2!=NULL){
				if(k!=-1){
					if(P->data[k]==p2->data){
						p2 = p2->next;
						k--;
					}else{
						printf("%dNO\n",i);
						break;
					}		
				}		
			}
			if(p1==NULL){
			if(p2==NULL){
				printf("%dYes\n",i);
			}
			}
			
		}
	}

}

void Output(node *L){
	node *head;
	head  = L->next;
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;
	}

}

int main(void){
	all *L;
	L = Create();
//	Output(L);
	Calcu(L);
	return 0;
}
