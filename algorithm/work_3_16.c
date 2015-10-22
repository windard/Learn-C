#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define MAXSIZE	 4

typedef char datatype;
struct sequeue{
	datatype data[MAXSIZE];
	int 	 rear,quelen;
};
struct sequeue *L;

int FullQ(struct sequeue *sq){
	if(sq->quelen==MAXSIZE){
		return 1;
	}else{
		return 0;
	}
}

int EmptyQ(struct sequeue *sq){
	if(sq->quelen==0){
		return 1;
	}else{
		return 0;
	}
}

int EnQueueQ(struct sequeue *sq,datatype x){
	if(FullQ(sq)){
		printf("\nqueue if full \n");
		return 0;
	}else{
		sq->data[(sq->rear+1)%MAXSIZE] = x;
		sq->rear++;
		sq->quelen++;
		return 1;
	}
}

datatype *DeQueueQ(struct sequeue *sq){
	datatype 	*ret;
	if(EmptyQ(sq)){
		printf("queue is empty\n");
		return NULL;
	}else{
		ret = (datatype *)malloc(sizeof(datatype));
		*ret = sq->data[(sq->rear-sq->length+1)%MAXSIZE];
		sq->rear--;
		sq->quelen--;
		return ret;
	}
}

int main(int argc, char const *argv[])
{
	struct 	sequeue 		 *L;
	char 					 a;
	char 					 *b;
	int 					 flag=1;
	L = (struct sequeue *)malloc(sizeof(struct sequeue));
	L->rear = -1;
	L->quelen = 0;
	while(flag){
		printf("\nPlease Input A Char\n");
		a = getche();
		flag = EnQueueQ(L,a);
	}
	b=DeQueueQ(L);
	while(b!=NULL){
		printf("%c\n",*b);
		b=DeQueueQ(L);
	}
	return 0;
}
