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

void NinOrder(node *p){
	node * stack[MAXSIZE];
	node * s;
	int top = -1;
	s = p;
	while(top!=-1||s!=NULL){
		while(s!=NULL){
			if(top==MAXSIZE-1){
				printf("OVERFLOW\n");
				return;
			}else{
				top ++;
				stack[top] = s;
				s = s->lchild;
			}
		}
		s = stack[top];
		top --;
		printf("%c",s->data);
		s = s->rchild;
	}
}

void Preorder(node *L){
	node * stack[MAXSIZE];
	node * s;
	int top = -1;
	s = L;
	while(top!=-1||s!=NULL){
		while(s!=NULL){
			if(top==MAXSIZE-1){
				printf("OVERFLOW\n");
				return;
			}else{
				top ++;
				stack[top] = s;
				printf("%c",s->data);
				s = s->lchild;
			}
		}
		s = stack[top];
		top --;
		s = s->rchild;
	}
}

int main(int argc, char const *argv[])
{
	root = CreateTree();
	Preorder(root);
	return 0;
}
