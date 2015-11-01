#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

typedef char datatype;
typedef struct linknode
{
	datatype	 	data;
	struct  linknode   *next;
}linkstring;
linkstring *S;

linkstring * CreatListR1(){
	char 			ch;
	linkstring		*head,*s,*r;
	head = (linkstring*)malloc(sizeof(linkstring));
	r = head;
	printf("请输入串L中的元素，以#结束\n");	
	while((ch=getche())!='#'){
		s = (linkstring*)malloc(sizeof(linkstring));
		s->data = ch;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}

void Output(linkstring *L){
	linkstring 	*head;
	head = L;
	head = head->next;
	printf("\n串L中的元素为：\n");	
	while(head->next!=NULL){
		printf("%3c",head->data );
		head = head->next;
	}
	printf("%3c",head->data );
}

linkstring * Replace(linkstring *L){
	linkstring *head;
	head = L;
	head = head->next;
	while(head!=NULL){
		if(head->data == 'c'){
			head->data = 's';
			head = head->next;
		}else{
			head = head->next;
		}
	}	
	return L;
}

int main(int argc, char const *argv[])
{
	linkstring	*L;
	L = CreatListR1();
	Output(L);
	L = Replace(L);
	Output(L);
	return 0;
}
