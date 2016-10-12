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
		printf("%3d",head->data );
		head = head->next;
	}
	printf("%3d",head->data );
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
		printf("%3d",head->data );
		head = head->next;
	}
	printf("%3d",head->data );
}

int main()
{
	linklist	*L,*head;
	int 		num;
	L = CreatList();
	head = L;
	do{
		printf("Please Input Num (Num <= 30):");
		scanf("%d",&num);		
	}while(num>30);
	for (int j = 0; j < 7; ++j)
	{
		for (int i = 0; i < num-2; i++)
		{	
			head = head->next;
		}
		printf("%3d",head->next->num);
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
		scanf("%d",&ch);
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
		printf("%3d",head->data );
		head = head->next;
	}
	printf("%3d\n",head->data );
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
		scanf("%d",&ch);
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
		printf("%3d",head->data );
		head = head->next;
	}
	printf("%3d\n",head->data );
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
	scanf("%d",&min);
	printf("Please Input Max:");
	scanf("%d",&max);
	Delete(L,min,max);
	Output(L);
	return 0;
}
***********************************************************************************/