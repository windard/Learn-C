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

void PreOrder(node *L){
	if(L!=NULL){
		printf("%c",L->data);
		PreOrder(L->lchild);
		PreOrder(L->rchild);
	}
}

void InOrder(node *L){
	if(L!=NULL){
		InOrder(L->lchild);
		printf("%c",L->data);
		InOrder(L->rchild);
	}
}

void PostOrder(node *L){
	if(L!=NULL){
		PostOrder(L->lchild);
		PostOrder(L->rchild);
		printf("%c",L->data);
	}
}

void Layer(node *L){
	node *Q[MAXSIZE];
	node *s;
	int front=0,rear=1;
	Q[rear]=L;
	while(front<rear){
		front ++;
		s = Q[front];
		printf("%c",s->data);
		if(s->lchild!=NULL){
			rear++;
			Q[rear] = s->lchild;
		}
		if(s->rchild!=NULL){
			rear++;
			Q[rear] = s->rchild;
		}
	}

}

int main(int argc, char const *argv[])
{
	root = CreateTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	Layer(root);
	return 0;
}
