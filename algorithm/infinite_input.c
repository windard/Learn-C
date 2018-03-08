#include "stdio.h"
#include "stdlib.h"

typedef int datatype;
typedef struct node
{
    datatype data;
    struct node *next;
}InputNode;


InputNode * CreatList(){
    int              ch;
    InputNode        *head, *s, *r;
    head = (InputNode*)malloc(sizeof(InputNode));
    r = head;
    printf("请输入顺序表L中的元素，以 EOF 结束\n");
    while(scanf("%d", &ch) != EOF){
        s = (InputNode*)malloc(sizeof(InputNode));
        s->data = ch;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return head;
}


void Output(InputNode *L){
    InputNode    *head;
    head = L;
    head = head->next;
    printf("\n循环表L中的元素为：\n");
    while(head->next != NULL){
        printf("%3d", head->data);
        head = head->next;
    }
    printf("%3d", head->data);
}


int main(int argc, char const *argv[])
{
    InputNode    *L;
    L = CreatList();
    Output(L);
    return 0;
}