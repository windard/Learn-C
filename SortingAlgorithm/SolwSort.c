#include "stdio.h"

#define N 15


void solwSort(int a[], int start, int end){
    if (start >= end) return;

    int     m;
    int     t;
    m = (start + end) / 2;

    solwSort(a, start, m);
    solwSort(a, m+1, end);

    if (a[m] > a[end]){
        t      = a[end];
        a[end] = a[m];
        a[m]   = t;
    }

    solwSort(a, start, end-1);

}

int main(int argc, char const *argv[])
{
    int         t;
    int         a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

    printf("Origin : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    solwSort(a, 0, N-1);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }
    return 0;
}
