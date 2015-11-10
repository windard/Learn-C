#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

#define SIZEMAX 40 + 10
typedef struct node{
	int 	data[SIZEMAX];
	int 	last;
}; 

node * Create(){
	node		 *L;
	int 		 num,i;
	L = (node*)malloc(sizeof(node));
	scanf("%d",&num);
	if(num>10){
		return NULL;
	}
	for(i=0;i<num;i++){
		scanf("%d %d",&L->data[2*i],&L->data[2*i+1]);
	}
	L->last = num;
	return L;
}

void Output(node *L){
	int i,flag=1;
	printf("%d ",L->last );
	for(i=0;i<(2*L->last);i++){
		if(flag){
			flag=0;
		}else{
			printf(" ");
		}
		printf("%d",L->data[i]);
	}
}

node * Plus(node *L1,node *L2){
	node 		*P;
	int 		i=0,j=0,sum;
	P = (node *)malloc(sizeof(node));
	P->last=0;
	while(i!=L1->last&&j!=L2->last){
		if(L1->data[2*i+1]==L2->data[2*j+1]){
			sum=L1->data[2*i]+L2->data[2*j];
			if(sum){
				P->data[2*P->last] = sum;
				P->data[2*P->last+1] = L1->data[2*i+1];
				P->last ++;
			}
			i ++;
			j ++;
		}else if(L1->data[2*i+1]>L2->data[2*j+1]){
			P->data[2*P->last] = L1->data[2*i];
			P->data[2*P->last+1] = L1->data[2*i+1];
			P->last ++;		
			i ++;	
		}else{
			P->data[2*P->last] = L2->data[2*j];
			P->data[2*P->last+1] = L2->data[2*j+1];
			P->last ++;		
			j ++;	
		}
	}
	if(i==L1->last){
		for(j;j<L2->last;j++){
			P->data[2*P->last] = L2->data[2*j];
			P->data[2*P->last+1] = L2->data[2*j+1];
			P->last ++;					
		}
	}else{
		for(i;i<L1->last;i++){
			P->data[2*P->last] = L1->data[2*i];		
			P->data[2*P->last+1] = L1->data[2*i+1];		
			P->last ++;							
		}
	}
	return P;
}

node * Minus(node *L1,node *L2){
	node 		*P;
	int 		i=0,j=0,sum;
	P = (node *)malloc(sizeof(node));
	P->last=0;
	while(i!=L1->last&&j!=L2->last){
		if(L1->data[2*i+1]==L2->data[2*j+1]){
			sum=L1->data[2*i]-L2->data[2*j];
			if(sum){
				P->data[2*P->last] = sum;
				P->data[2*P->last+1] = L1->data[2*i+1];
				P->last ++;
			}
			i ++;
			j ++;
		}else if(L1->data[2*i+1]>L2->data[2*j+1]){
			P->data[2*P->last] = L1->data[2*i];
			P->data[2*P->last+1] = L1->data[2*i+1];
			P->last ++;		
			i ++;	
		}else{
			P->data[2*P->last] = -L2->data[2*j];
			P->data[2*P->last+1] = L2->data[2*j+1];
			P->last ++;		
			j ++;	
		}
	}
	if(i==L1->last){
		for(j;j<L2->last;j++){
			P->data[2*P->last] = L2->data[2*j];
			P->data[2*P->last+1] = L2->data[2*j+1];
			P->last ++;					
		}
	}else{
		for(i;i<L1->last;i++){
			P->data[2*P->last] = L1->data[2*i];		
			P->data[2*P->last+1] = L1->data[2*i+1];		
			P->last ++;							
		}
	}
	return P;
}


int main(int argc, char const *argv[])
{
	node *L1,*L2,*L3,*L4;
	L1 = Create();
	Output(L1);
	L2 = Create();
	L3 = Plus(L1,L2);
	L4 = Minus(L1,L2);
	Output(L3);
	printf("\n");
	Output(L4);
	return 0;
}
