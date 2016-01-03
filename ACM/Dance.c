#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
	char	name;
	struct node* next;
}node;

typedef struct seq{
	node *front,*rear;
}seq;

seq *linklist;

node *Create(void){
	node *S,*P,*head;
	char ch;
	head=(node*)malloc(sizeof(node));
	P=head;
	fflush(stdin);
	while((ch=getchar())!='#'){
		S = (node*)malloc(sizeof(node));
		S->name=ch;
		P->next=S;
		P=S;
	}
	P->next=NULL;
	return head;
}

void Output(node* S){
	node	*head;
	head=S->next;
	while(head!=NULL){
		printf("%c",head->name);
		head=head->next;
	}
}		

seq* setNull(seq* sing){
	sing->front=(node*)malloc(sizeof(node));
	sing->front->next=NULL;	
	sing->rear=sing->front;
	return sing;
}

void EnQueue(seq* sing,char ch){
	sing->rear->next=(node*)malloc(sizeof(node));
	sing->rear=sing->rear->next;
	sing->rear->name=ch;
	sing->rear->next=NULL;
}

char DeQueue(seq *sing){
	node	*head;
	char	result;
	head=sing->front->next;
	sing->front->next=head->next;
	result=head->name;
	return result;
}

void Count(int num,char mn,char wn,node *men,node *women){
	int		i,j;
	int		mnu=0,wnu=0;
	node	*head1,*head2;
	node	*P;
	seq		*sing;
	char	name;
	int		find=0;
	sing=(seq*)malloc(sizeof(seq));
	sing=setNull(sing);
	head1=men->next;
	head2=women->next;
	while(head1!=NULL){
		mnu++;
		head1=head1->next;
	}
	while(head2!=NULL){
		wnu++;
		head2=head2->next;
	}
	if(mnu>wnu){
		for(i=0;i<num;i++){
			head1=men->next;	
			while(head1!=NULL){
				EnQueue(sing,head1->name);
				head1=head1->next;
			}
		}
		for(i=0;i<num;i++){
			head2=women->next;
			while(head2!=NULL){
				name=DeQueue(sing);
				if(name==mn&&head2->name==wn){
					printf("Meet He At No.%d Sing \n",i+1);
					printf("This is they No.%d meet\n",find+1);
					find++;
				}
				head2=head2->next;
			}
		}
		if(find==0){
			printf("They Can't Meet");
		}
	}else{
		for(i=0;i<num;i++){
			head2=women->next;	
			while(head2!=NULL){
				EnQueue(sing,head2->name);
				head2=head2->next;
			}
		}
		for(i=0;i<num;i++){
			head1=men->next;
			while(head1!=NULL){
				name=DeQueue(sing);
				if(name==wn&&head1->name==mn){
					printf("Meet She At No.%d Sing \n",i+1);
					printf("This is they No.%d meet \n",find+1);
					find++;
				}
				head1=head1->next;
			}
		}
		if(find==0){
			printf("They Can't Meet");
		}
	}
}

int main(void){
	node *men,*women;
	seq  *sing;
	int  num,i,j;
	char	mn,wn;
	printf("Please Input Men's name,End with '#'\n");
	men=Create();
	printf("Please Input Women's name,End with '#'\n");
	women=Create();
	// Output(men);
	// Output(women);
	printf("How Many Sings?\n");
	scanf("%d",&num);
	printf("The man's name:\n");
	fflush(stdin);
	mn = getchar();
	printf("The woman's name:\n");
	fflush(stdin);
	wn = getchar();
	Count(num,mn,wn,men,women);
	return 0;
}
