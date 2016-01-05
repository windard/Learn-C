#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef char datatype;
typedef struct node
{
	int weight;
	datatype data;
	int lchild,rchild,parent;
}hufmtree;

#define EPS 1e-5

int Counter(hufmtree tree[],hufmtree single,int deep){
	static int 		num;
	if(single.lchild == -1 && single.rchild == -1){
		num += deep * single.weight;
	}else{
		Counter(tree,tree[single.lchild],deep+1);
		Counter(tree,tree[single.rchild],deep+1);
	}
	return num;
}

void Create(int num){
	int 	N,M;
	int 	i,j,p1,p2;
	int 	ch;
	int 	small1,small2;
	N = num;
	M = num*2 - 1;
	hufmtree  tree[M];
	for(i=0;i<M;i++){
		tree[i].parent = -1;
		tree[i].lchild = -1;
		tree[i].rchild = -1;
		tree[i].weight = 0;
		tree[i].data  = '0';
	}
	for(i=0;i<N;i++){
		scanf("%d",&ch);
		tree[i].weight = ch;
	}
	for(i=N;i<M;i++){
		p1 = p2 = 0;
		small1 = small2 = 10000;
		for(j=0;j<i;j++){
			if(tree[j].parent == -1){
				if(tree[j].weight - small1 < EPS){
					small2 = small1;
					small1 = tree[j].weight;
					p2 = p1;
					p1 = j;
				}else if(tree[j].weight - small2 < EPS){
					small2 = tree[j].weight;
					p2 = j;
				}
			}
		}
		tree[p1].parent = i;
		tree[p2].parent = i;
		tree[i].lchild = p1;
		tree[i].rchild = p2;
		tree[i].parent = -1;
		tree[i].weight = tree[p1].weight + tree[p2].weight;
	}
	// for(j=0;j<M;j++){
	// 	printf("%d ",tree[j].weight);
	// }
	int 	result;
	result = Counter(tree,tree[M-1],0);
	printf("%d\n",result);
}

int main(int argc, char const *argv[])
{
	int num;
	scanf("%d",&num);
	Create(num);
	return 0;
}
