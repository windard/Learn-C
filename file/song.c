//coding:GBK
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu
{
   char xh[5];
   char XB[5];
   char name[5];
   char SS[5];
   char Tel[20];  
}stutype;  

typedef struct node
{ 
	stutype data;
	struct node *next;
}stuNode; 

stuNode * Create(){
	stuNode 	*head,*P,*L;
	FILE 	*fp;
	char 	s[80];
	char 	*buf;
	int 	i;
	// char 	*ch;
	int 	ch=1;
	char 	a[5],b[5],c[5],d[5],e[20];
	if((fp=fopen("read.txt","r"))==NULL){
		printf("Can't Open File\n");
		exit(0);
	}
	head = (stuNode*)malloc(sizeof(stuNode));
	P = head;
	ch = fscanf(fp,"%s\t%s\t%s\t%s\t%s\n",&a,&b,&c,&d,&e);
	// while(ch){
	for(i=0;i<4;i++){
		ch = fscanf(fp,"%s\t%s\t%s\t%s\t%s\n",&a,&b,&c,&d,&e);
		L = (stuNode*)malloc(sizeof(stuNode));
		strcpy(L->data.xh,a);
		strcpy(L->data.XB,b);
		strcpy(L->data.name,c);
		strcpy(L->data.SS,d);
		strcpy(L->data.Tel,e);
		P->next = L;
		P = L;
	}
	P->next = NULL;
	fclose(fp);
	return head;
}

void Output(stuNode *head){
	stuNode 	*P;
	P = head->next;
	while(P!=NULL){
		printf("%s\n",P->data.xh );
		printf("%s\n",P->data.XB );
		printf("%s\n",P->data.name );
		printf("%s\n",P->data.SS );
		printf("%s\n",P->data.Tel );
		P = P->next;
	}
}

int main(int argc, char const *argv[])
{
	stuNode 	*head;
	head = Create();
	Output(head);
	return 0;
}
