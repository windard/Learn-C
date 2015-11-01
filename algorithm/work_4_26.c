#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

#define SMAX 16

typedef int datatype;

typedef struct 
{
	int 			i,j;
	datatype		v;
}node;

typedef	struct 
{
	int m,n,t;
	node data[SMAX];
}spmatrix;

spmatrix * Create(){
	int num,row,col,nozero=0;
	spmatrix * 	L;
	L = (spmatrix *)malloc(sizeof(spmatrix));
	printf("\n请输入矩阵行数：\n");
	scanf("%d",&row);
	printf("\n请输入矩阵列数：\n");
	scanf("%d",&col);
	L->m=row;
	L->n=col;
	for (int row1 = 0; row1 < row; row1++)
	{
		for (int col1 = 0; col1 < col; col1++)
		{
			printf("请输入第%d行第%d个数\n",row1+1,col1+1 );
			scanf("%d",&num);
			if(num!=0){
				L->data[nozero].i=row1;
				L->data[nozero].j=col1;
				L->data[nozero].v=num;
				nozero++;
			}
		}
	}
	L->t = nozero;
	return L;
}

void Output(spmatrix *L){
	int flag=0;
	for (int row1 = 0; row1 < L->m; row1++)
	{
		printf("|");
		for (int col1 = 0; col1 < L->n; col1++)
		{
			flag = 0;
			for (int num = 0; num < L->t ; num++)
			{
				if(L->data[num].i==row1&&L->data[num].j==col1){
					printf("%4d",L->data[num].v);
					flag = 1;
				}
			}
			if(!flag){
				printf("   0");
			}
		}
		printf(" |\n");
	}
}

spmatrix* TransMat(spmatrix *a){
	int 			i,j,bno=0;
	spmatrix 		*b;
	b = (spmatrix*)malloc(sizeof(spmatrix));
	b->m = a->n;
	b->n = a->m;
	b->t = 0;
	if(a->t==0)
		return b;
	for (i = 0; i < a->n; i++)
	{
		for(j = 0;j <a->t; j++){
			if(a->data[j].j == i){
				b->data[bno].i = a->data[j].j;
				b->data[bno].j = a->data[j].i;
				b->data[bno].v = a->data[j].v;
				bno++;
			}
		}
	}
	b->t = bno;
	return b;
}

spmatrix * Multi(spmatrix * a,spmatrix *b){
	int 		num,cnum=0;
	int 		row,col,at,bt;
	spmatrix *c;
	c = (spmatrix*)malloc(sizeof(spmatrix));
	if(a->m==b->n&&a->n==b->m){
		c->m = a->m;
		c->n = b->n;
		for (row = 0; row < c->m; row++)
		{
			for (col = 0; col < c->n; col++)
			{
				num = 0;
				for (at = 0; at < a->t; at++)
				{
					for (bt = 0; bt < b->t; bt++)
					{
						if (a->data[at].i==row&&b->data[bt].j==col)
						{
							if (a->data[at].j==b->data[bt].i)
							{
								num+=a->data[at].v*b->data[bt].v;
							}
						}
					}
				}
				if(num!=0){
					c->data[cnum].i=row;
					c->data[cnum].j=col;
					c->data[cnum].v=num;
					cnum++;
				}
			}
		}			
		c->t=cnum;
		return c;		
	}else{
		printf("Can't Multi\n");
	}

}

int main(int argc, char const *argv[])
{
	spmatrix *L,*N,*M;
	L=Create();
	Output(L);
	N=Create();
	Output(N);	
	M = Multi(L,N);
	printf("\n");
	Output(M);
	// L = TransMat(L);
	// printf("\n");
	// Output(L);
	return 0;
}

