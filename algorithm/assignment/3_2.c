#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct node
{
	int 	data;
	struct node *lchild,*rchild;
};

node * Count(){
	node 	*root;
	node	*P,*S;
	root = (node*)malloc(sizeof(node));
	int 	num,ch;
	scanf("%d",&num);
	for (int i = 0; i < num; i++)
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
	return root;
}
void OutPut(node *root){
	if(root!=NULL){
		OutPut(root->lchild);
		printf("%d ",root->data);
		OutPut(root->rchild);
	}
}

int main(int argc, char const *argv[])
{
	node *root;
	root = Count();
	OutPut(root);
	return 0;
}