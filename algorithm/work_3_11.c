#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

typedef char datatype;

struct Node {
	datatype 		element;
	struct 	Node 	*next;
};
struct Node *top;

struct Node * CreatListR1(){
	char 			ch;
	struct Node		*head,*s,*r;
	head = (struct Node*)malloc(sizeof(struct Node));
	r = head;
	printf("\n请输入顺序表L中的元素，以#结束\n");	
	while((ch=getche())!='#'){
		s = (struct Node*)malloc(sizeof(struct Node));
		s->element = ch;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}

void Output(struct Node *L){
	struct Node 	*head;
	head = L;
	head = head->next;
	printf("\n循环表L中的元素为：\n");	
	while(head->next!=NULL){
		printf("%3c",head->element );
		head = head->next;
	}
	printf("%3c",head->element );
}

datatype *PopL(struct Node *S){
	datatype *ret;
	if(S==NULL){
		printf("Stack is underflow\n");
		return NULL;
	}else{
		ret = (datatype *)malloc(sizeof(datatype));
		*ret = S->element;
		return ret;
	}
}

struct Node * PushL(struct Node *S,datatype e){
	struct Node *p;
	p=(struct Node *)malloc(sizeof(struct Node));
	p->element = e;
	p->next    = S;
	S = p;
	return S;
}

int JudgeL(struct Node *L){
	int 				length=0;
	struct Node 		*p;
	struct Node 		*head;
	head = L;
	while(head!=NULL){
		length++;
		head = head->next;
	}
	length--;
	L = L->next;
	for (int i = 0; i < (length+1)/2; i++)
	{
		p = PushL(p,L->element);
		L = L->next;
	}
	if(length%2==0){
		while(L!=NULL){
			if(*PopL(p)==L->element){
				p = p->next;
				L = L->next;
			}else{
				printf("%c\n",*PopL(p) );
				return 0;
			}			
		}
		return 1;
	}else{
		p = p->next;
		while(L!=NULL){
			if(*PopL(p)==L->element){
				p = p->next;
				L = L->next;
			}else{
				return 0;
			}			
		}
		return 1;
	}
}

int main(int argc, char const *argv[])
{
	struct Node 	*L;
	int flag;
	do{
		L = CreatListR1();
		Output(L);			
		flag=JudgeL(L);
	}while(!flag);
	return 0;
}
