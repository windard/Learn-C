#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef char vextype;

typedef struct node
{
	int 	adjvex;
	struct node * next;
};

typedef struct vexnode
{
	vextype 	vertex;
	node 		*link;
};

vexnode ga[4];
int 	visited[4]={0};

void Create(){
	int 	i,j,k;
	node 	*s;
	int 	N=4;
	int 	M=5;
	for(i=0;i<N;i++){
		ga[i].vertex = getchar();
		ga[i].link = NULL;
	}
	for(k=0;k<M;k++){
		scanf("%d%d",&i,&j);
		s = (node*)malloc(sizeof(node));
		s->adjvex = j;
		s->next = ga[i].link;
		ga[i].link = s;
	}
}

void DFSL(int 	i){
	node 	*p;
	// printf("%c\n",ga[i].vertex );
	visited[i] = 1;
	p = ga[i].link;
	while(p!=NULL){
		if(visited[p->adjvex]==0){
			DFSL(p->adjvex);
		}
	p = p->next;
	}
}
int main(int argc, char const *argv[])
{
	Create();
	int i,j;
	scanf("%d%d",&i,&j);
	DFSL(i);
	if(visited[j]==0){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
	return 0;
}
