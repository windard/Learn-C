#include "stdio.h"
#include "stdlib.h"

typedef int datatype;
typedef struct node
{
    char name[100];
    datatype age;
    datatype grade;
    struct node *next;
} InputNode;


InputNode *CreatList()
{
    char name[100];
    int age;
    int grade;
    int length;
    InputNode *head, *s, *r;
    head = (InputNode *)malloc(sizeof(InputNode));
    r = head;
    scanf("%d", &length);
    scanf("%s", r->name);
    scanf("%d", &r->age);
    scanf("%d", &r->grade);
    for (int i = 1; i < length; i++)
    {
        s = (InputNode *)malloc(sizeof(InputNode));
        scanf("%s", s->name);
        scanf("%d", &s->age);
        scanf("%d", &s->grade);
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return head;
}

void Output(InputNode *L)
{
    InputNode *head;
    head = L;
    while (head->next != NULL)
    {
        printf("%s %d %d\n", head->name, head->age, head->grade);
        head = head->next;
    }
    printf("%s %d %d\n", head->name, head->age, head->grade);
}

InputNode *SortByName(InputNode *L) {
    InputNode *head, *last, *temp;
    int       flag = 1;
    while(flag){
        flag = 0;
        head = L;
        last = NULL;
        while (head->next != NULL) {
            if (head->next->name[0] < head->name[0]) {
                temp = head->next;
                head->next = temp->next;
                temp->next = head;
                if (last != NULL)
                {
                    last->next = temp;
                }
                else
                {
                    L = temp;
                }
                last = temp;
                flag = 1;
            }
            else
            {
                last = head;
                head = head->next;
            }
        }
    }
    return L;
}

InputNode *SortByAge(InputNode *L)
{
    InputNode *head, *last, *temp;
    int flag = 1;
    while (flag)
    {
        flag = 0;
        head = L;
        last = NULL;
        while (head->next != NULL)
        {
            if (head->next->age < head->age)
            {
                temp = head->next;
                head->next = temp->next;
                temp->next = head;
                if (last != NULL)
                {
                    last->next = temp;
                }
                else
                {
                    L = temp;
                }
                last = temp;
                flag = 1;
            }
            else
            {
                last = head;
                head = head->next;
            }
        }
    }
    return L;
}

InputNode *SortByGrade(InputNode *L){
    InputNode *head, *last, *temp;
    int       flag = 1;
    while(flag){
        flag = 0;
        head = L;
        last = NULL;
        while(head->next != NULL){
            if (head -> next -> grade < head -> grade) {
                temp = head->next;
                head->next = temp->next;
                temp->next = head;
                if (last != NULL) {
                    last -> next = temp;
                }else{
                    L = temp;
                }
                last = temp;
                flag = 1;
            }else {
                last = head;
                head = head -> next;
            }
        }
    }
    return L;
}

InputNode *DealWithEqualGrade(InputNode *L){
    InputNode *head, *before, *after, *last, *M;
    int       flag;
    head = L;
    last = NULL;
    before = NULL;
    after = NULL;
    flag = 0;
    while(head -> next != NULL){
        if (head -> next -> grade == head -> grade) {
            if (!flag)
            {
                flag = 1;
                before = last;
            }
        }else {
            if (flag) {
                after = head -> next;
                head -> next = NULL;
                if (before != NULL){
                    M = SortByName(before->next);
                    before->next = M;
                }else{
                    M = SortByName(L);
                    L = M;
                }
                while(M->next!=NULL){
                    M = M -> next;
                }
                M -> next = after;
                flag = 0;
            }
        }
        last = head;
        head = head->next;
    }
    return L;
}

InputNode *DealWithEqualGradeAndName(InputNode *L)
{
    InputNode *head, *before, *after, *last, *M;
    int flag;
    head = L;
    last = NULL;
    before = NULL;
    after = NULL;
    flag = 0;
    while (head->next != NULL)
    {
        if (head->next->grade == head->grade && head->next->name[0] == head->name[0])
        {
            if (!flag)
            {
                flag = 1;
                before = last;
            }
        }
        else
        {
            if (flag)
            {
                after = head->next;
                head->next = NULL;
                if (before != NULL)
                {
                    M = SortByAge(before->next);
                    before->next = M;
                }
                else
                {
                    M = SortByAge(L);
                    L = M;
                }
                while (M->next != NULL)
                {
                    M = M->next;
                }
                M->next = after;
                flag = 0;
            }
        }
        last = head;
        head = head->next;
    }
    return L;
}

int main(int argc, char const *argv[])
{
    InputNode *L;
    L = CreatList();
    L = SortByGrade(L);
    L = DealWithEqualGrade(L);
    L = DealWithEqualGradeAndName(L);
    // L = SortByName(L);
    // L = SortByAge(L);
    Output(L);
    return 0;
}
