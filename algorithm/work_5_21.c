#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

#define MAXSIZE 1024

typedef int datatype;
typedef struct node{
	datatype data;
	struct node * lchild,* rchild;
};

node * root;

node * CreateTree(){
	char 	ch;
	node   *Q[MAXSIZE];
	node 	*s,*root;
	int  	front,rear;
	root  = NULL;
	front = 1;
	rear  = 0;
	while((ch=getchar())!='#'){
		s = NULL;
		if(ch!='@'){
			s = (node*)malloc(sizeof(node));
			s->data = ch;
			s->lchild = NULL;
			s->rchild = NULL;
		}
		rear ++;
		Q[rear] = s;
		if(rear==1){
			root = s;
		}else{
			if(s&&Q[front]){
				if(rear%2==0)
					Q[front]->lchild = s;
				else
					Q[front]->rchild = s;					
			}
			if(rear%2==1)
				front ++;	
		}
	}
	return root;
}

void Change(node *L){
	node * temp;
	if(L!=NULL){
		temp = L->lchild;
		L->lchild = L->rchild;
		L->rchild = temp;
		Change(L->lchild);
		Change(L->rchild);
	}
}

void PreOrder(node *L){
	if(L!=NULL){
		printf("%c",L->data);
		PreOrder(L->lchild);
		PreOrder(L->rchild);
	}
}

int main(int argc, char const *argv[])
{
	root = CreateTree();
	PreOrder(root);
	Change(root);
	printf("\n");
	PreOrder(root);
	return 0;
}
