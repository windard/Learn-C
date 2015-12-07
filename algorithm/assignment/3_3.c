#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct node
{
	int 	data;
	struct node *lchild,*rchild;
};

typedef struct line
{
	int 	data;
	struct line *next;
};

typedef struct bittree
{
	struct node *root;
	struct line *head;
};

bittree * Count(){
	node 	*root;
	node	*P,*S;
	root = (node*)malloc(sizeof(node));
	bittree *Last;
	line  	*head,*M,*N;
	int 	num,ch,i;
	scanf("%d",&num);
	for (i = 0; i < num; i++)
	{
		P = root;
		scanf("%d",&ch);
		if(i==0){
			P->data = ch; 
			P->lchild = NULL;
			P->rchild = NULL;
		}else{
			S = (node*)malloc(sizeof(node));
			S->data = ch;
			S->lchild = NULL;
			S->rchild = NULL;
			while(P->lchild!=NULL||P->rchild!=NULL){
				if(P->data>ch){
					if(P->lchild==NULL){
						break;
					}
					P = P->lchild;
				}else{
					if(P->rchild==NULL){
						break;
					}
					P = P->rchild;
				}				
			}
			if(P->data>ch){
				P->lchild = S;
			}else{
				P->rchild = S;
			}
		}
	}
	scanf("%d",&num);
	head = (line*)malloc(sizeof(line));
	Last = (bittree*)malloc(sizeof(bittree));
	Last->root = root;
	Last->head = head;
	M = head;
	for (i = 0; i < num; i++)
	{
		scanf("%d",&ch);
		N = (line*)malloc(sizeof(line));
		N->data = ch;
		M->next = N;
		M = N;
	}
	M->next = NULL;
	return Last;
}

void OutPut(node *root){
	if(root!=NULL){
		OutPut(root->lchild);
		printf("%d ",root->data);
		OutPut(root->rchild);
	}
}

void CalCul(node *head,int P){
	node	*root,*S;
	root = head;
	int		parent,lchild,rchild,font,rear;
	if(root->data==P){
		parent = 0;
	}else{
		while(root!=NULL){
			S = root;
			if(root->data>P){
				root = root->lchild;
			}else if(root->data<P){
				root = root->rchild;
			}else{
				parent = S->data;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	bittree *root;
	root = Count();
	// OutPut(root);
	return 0;
}