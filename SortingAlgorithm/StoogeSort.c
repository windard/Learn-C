#include "stdio.h"

#define N 15


void stoogeSort(int a[], int start, int end){
    int     t;
    int     s;

    if (a[start] > a[end]){
        t        = a[start];
        a[start] = a[end];
        a[end]   = t;
    }
    if (start + 1 == end){
        return;
    }

    s = (end - start + 1) / 3;
    stoogeSort(a, start, end - s);
    stoogeSort(a, start + s, end);
    stoogeSort(a, start, end - s);

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

    stoogeSort(a, 0, N-1);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }
    return 0;
}
