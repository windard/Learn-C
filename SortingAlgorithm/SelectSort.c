#include "stdio.h"

#define N 15

void selectSort(int a[]){
    int     i, j, m, t;
    for (i = 0; i < N; ++i)
    {
        m = i;
        for (j = i+1; j < N; ++j)
        {
            if (a[j] < a[m]) {
                m = j;
            }
        }
        t    = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

int main(int argc, char const *argv[])
{
    int         a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

    printf("Origin : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    selectSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    return 0;
}
