#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

typedef char datatype;
typedef struct node
{
	datatype	 	data;
	struct  node   *next;
}linklist;

linklist * CreatListR1(){
	char 			ch;
	linklist		*head,*s,*r;
	head = (linklist*)malloc(sizeof(linklist));
	r = head;
	printf("请输入循环表L中的元素，以#结束\n");	
	while((ch=getche())!='#'){
		s = (linklist*)malloc(sizeof(linklist));
		s->data = ch;
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
	printf("\n循环表L中的元素为：\n");	
	while(head->next!=L){
		printf("%3c",head->data );
		head = head->next;
	}
	printf("%3c",head->data );
}

void Sort(linklist *L,linklist *L2,linklist *L3){
	linklist 	*head,*s1,*s2,*s3,*p;
	s1 = L;
	s2 = L2;
	s3 = L3;
	head = L->next;
	while((head->next)!=L){
		if((head->data >= '0')&&(head->data <= '9')){
			s2->next = head;
			s2 = head;
		}else if(((head->data >='A')&&(head->data <= 'Z'))||((head->data >= 'a')&&(head->data <= 'z'))){
			s1->next = head;
			s1 = head;
		}else{
			s3->next = head;
			s3 = head;
		}
		head = head->next;
	}
	if((head->data >= '0')&&(head->data <= '9')){
		s2->next = head;
		s2 = head;
	}else if(((head->data >='A')&&(head->data <= 'Z'))||((head->data >= 'a')&&(head->data <= 'z'))){
		s1->next = head;
		s1 = head;
	}else{
		s3->next = head;
		s3 = head;
	}
	s1->next = L;
	s2->next = L2;
	s3->next = L3;

}

int main(int argc, char const *argv[])
{
	linklist	*L;
	linklist 	*L2,*L3;
	L = CreatListR1();
	Output(L);
	L2 = (linklist*)malloc(sizeof(linklist));
	L3 = (linklist*)malloc(sizeof(linklist));
	Sort(L,L2,L3);
	Output(L);
	Output(L2);
	Output(L3);
	return 0;
}
