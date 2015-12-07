#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct node{
	char  data;
	struct node* lchild,*rchild;
};

node* Create(){
	char 		ch;
	node		*root,*P,*S;
	node 		*Q[1024];
	int 		font,rear;
	font = 1;
	rear = 0;
	while((ch=getchar())!='#'){
		S=NULL;
		if(ch!='@'){
			S = (node*)malloc(sizeof(node));
			S->data = ch;
			S->lchild = NULL;
			S->rchild = NULL;
		}
		rear++;
		Q[rear] = S;
		if(rear==1){
			root = S;
		}else{
			if(S&&Q[font]){
				if(rear%2==0){
					Q[font]->lchild = S;
				}else{
					Q[font]->rchild = S;
				}				
			}
			if(rear%2==1){
				font++;
			}
		}
	}
	return root;
}

void OutPut(node *root){
	if(root!=NULL){		
		printf("%c\n",root->data );
		OutPut(root->lchild);
		OutPut(root->rchild);
	}
}

int Count(node *root){
	static int		num=0;
	int 	a,b;
	if(root!=NULL){
		if(root->lchild==NULL&&root->rchild==NULL){
			num ++;
			printf("%c ",root->data);
		}
		a = Count(root->lchild);
		b = Count(root->rchild);
	}
	return num;
}
int main(int argc, char const *argv[])
{
	node 		*root;
	int num;
	root = Create();
	// OutPut(root);
	num = Count(root);
	printf("\n%d",num );
	return 0;
}