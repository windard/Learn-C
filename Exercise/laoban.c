/****************************************** 第一题 ******************************************
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "time.h"

typedef int datatype;
typedef struct node
{
	datatype	 	data;
	struct  node   *next;
}linklist;

linklist * CreatList(){
	linklist		*head,*s,*r;
	head = (linklist*)malloc(sizeof(linklist));
	r = head;
    for(int i=0;i<6;i++){
		s = (linklist*)malloc(sizeof(linklist));
    	s->data = rand()%100;
		r->next = s;
		r = s;
    }
	r->next = NULL;
	return head;
}

void Output(linklist *L){
	linklist 	*head;
	head = L;
	head = head->next;
	while(head->next!=NULL){
		printf("%4d",head->data );
		head = head->next;
	}
	printf("%4d",head->data );
}

int main()
{
    srand(time(0));
	linklist	*L;
	L = CreatList();
	Output(L);
	return 0;
}
*************************************************************************************************/

/******************************** 第二题 ***********************************************************
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

typedef int datatype;
typedef struct node
{
	datatype 		num;
	datatype	 	data;
	struct  node   *next;
}linklist;

linklist * CreatList(){
	int 			ch;
	linklist		*head,*s,*r;
	int				nums[7] = {3,1,7,2,4,8,4};
	head = (linklist*)malloc(sizeof(linklist));
	r = head;
	r->data = nums[0];
	r->num = 1;
    for(int i=0;i<6;i++){
		s = (linklist*)malloc(sizeof(linklist));
		s->data = nums[i+1];
		s->num = i+2;
		r->next = s;
		r = s;
    }
	r->next = head;
	return head;
}

void Output(linklist *L){
	linklist 	*head;
	head = L;
	head = head->next;
	while(head->next!=NULL){
		printf("%4d",head->data );
		head = head->next;
	}
	printf("%4d",head->data );
}

int main()
{
	linklist	*L,*head;
	int 		num;
	L = CreatList();
	head = L;
	do{
		printf("Please Input Num (Num <= 30):");
		scanf("%4d",&num);
	}while(num>30);
	for (int j = 0; j < 7; ++j)
	{
		for (int i = 0; i < num-2; i++)
		{
			head = head->next;
		}
		printf("%4d",head->next->num);
		num = head->next->data;
		head->next = head->next->next;
		if(num != 1)
			head = head->next;
	}
	return 0;
}

******************************************************************************/

/********************************** 第五题 ****************************************
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

typedef int datatype;
typedef struct node
{
	datatype	 	data;
	struct  node   *next;
}linklist;

linklist * CreatList(){
	int 			ch;
	linklist		*head,*s,*r;
	head = (linklist*)malloc(sizeof(linklist));
	r = head;
	for (int i = 0; i < 6; ++i)
	{
		s = (linklist*)malloc(sizeof(linklist));
		scanf("%4d",&ch);
		s->data = ch;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}

void Output(linklist *L){
	linklist 	*head;
	head = L;
	head = head->next;
	while(head->next!=NULL){
		printf("%4d",head->data );
		head = head->next;
	}
	printf("%4d\n",head->data );
}


void Backword(linklist * L){
	linklist 	*head,*p,*s;
	p = L->next;
	head = L;
	while(head->next!=NULL){
		head = head->next;
	}
	s = p;
	L->next = head;
	while(head!=p){
		while(s->next!=head){
			s = s->next;
		}
		head->next = s;
		head = s;
		s = p;
	}
	head->next = NULL;
}

int main(int argc, char const *argv[])
{
	linklist	*L;
	L = CreatList();
	Output(L);
	Backword(L);
	Output(L);
	return 0;
}

***************************************************************************/

/******************************* 第六题 **************************************
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

typedef int datatype;
typedef struct node
{
	datatype	 	data;
	struct  node   *next;
}linklist;

linklist * CreatList(){
	int 			ch;
	linklist		*head,*s,*r;
	head = (linklist*)malloc(sizeof(linklist));
	r = head;
	for (int i = 0; i < 6; ++i)
	{
		s = (linklist*)malloc(sizeof(linklist));
		scanf("%4d",&ch);
		s->data = ch;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}

void Output(linklist *L){
	linklist 	*head;
	head = L;
	head = head->next;
	while(head->next!=NULL){
		printf("%4d",head->data );
		head = head->next;
	}
	printf("%4d\n",head->data );
}

void Delete(linklist *L,int min,int max){
	linklist 	*head;
	head = L;
	while(head->next!=NULL){
		if(head->next->data > min && head->next->data < max)
			head->next = head->next->next;
		head = head->next;
	}
}

int main(int argc, char const *argv[])
{
	linklist	*L;
	int 		min,max;
	L = CreatList();
	Output(L);
	printf("Please Input Min:");
	scanf("%4d",&min);
	printf("Please Input Max:");
	scanf("%4d",&max);
	Delete(L,min,max);
	Output(L);
	return 0;
}
***********************************************************************************/

/************************************** 第四题 **********************************************
#include "stdio.h"
// #include "conio.h"
#include "stdlib.h"

typedef int datatype;
typedef struct node
{
	datatype	 	data;
	struct  node   *next;
}linklist;

linklist * CreatList(){
	int 			ch;
	linklist		*head,*s,*r;
	head = (linklist*)malloc(sizeof(linklist));
	r = head;
	for (int i = 0; i < 6; ++i)
	{
		s = (linklist*)malloc(sizeof(linklist));
		scanf("%4d",&ch);
		s->data = ch;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}

void Output(linklist *L){
	linklist 	*head;
	head = L;
	head = head->next;
	while(head->next!=NULL){
		printf("%4d",head->data );
		head = head->next;
	}
	printf("%4d\n",head->data );
}

int FindMin(linklist *L){
	linklist 	*head;
	int 	min;
	head = L;
	head = head->next;
	min = head->data;
	while(head!=NULL){
		if(head->data<min)
			min = head->data;
		head = head->next;
	}
	return min;
}

void ChangeOrDelete(linklist *L,int min){
	linklist 	*head;
	head = L;
	head = head->next;
	while(head->next!=NULL){
		if(head->data == min){
			if(min%2!=0){
				head->data = head->next->data;
				head->next->data = min;
				break;
			}else{
				head->next = head->next->next;
				break;
			}
		}
		head = head->next;
	}
}

int main(int argc, char const *argv[])
{
	linklist	*L;
	int 	min;
	L = CreatList();
	Output(L);
	min = FindMin(L);
	printf("The Min Is :%4d\n",min );
	ChangeOrDelete(L,min);
	Output(L);
	return 0;
}

**************************************************************************************/

/*********************************** 第八题 **********************************************
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
	printf("Please Input String Which Ends with '@' :");	
	while((ch=getche())!='@'){
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
	while(head->next!=NULL){
		printf("%c",head->element );
		head = head->next;
	}
	printf("%c",head->element );
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
	L = CreatListR1();
	printf("\n");
	Output(L);		
	printf("\n");	
	flag=JudgeL(L);
	if (flag){
		printf("Yes \n");
	}else {
		printf("No \n");
	}
	return 0;
}

********************************************************************************************/