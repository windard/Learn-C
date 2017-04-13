#include "stdio.h"

#define N 15

// void insertSort(int a[]){
//     int     i, j, t, k;
//     for (i = 1; i < N; ++i)
//     {
//         for (j = i-1; j >= 0; --j)
//         {
//             if (a[j] < a[i]) break;
//         }

//         if (j != i-1) {
//             t = a[i];
//             for (k = i-1; k > j; --k)
//             {
//                 a[k+1] = a[k];
//             }
//             a[k+1] = t;
//         }
//     }
// }

// void insertSort(int a[]){
//     int     i, j, t;
//     for (i = 1; i < N; ++i)
//     {
//         if (a[i] < a[i-1]) {
//             t = a[i];
//             for (j = i-1; j >= 0 && a[j] > t; --j) {
//                 a[j+1] = a[j];
//             }
//             a[j+1] = t;
//         }
//     }
// }

void insertSort(int a[]){
    int     i, j, t;
    for (i = 1; i < N; ++i)
    {
        for (j = i-1; j >= 0 && a[j] > a[j+1]; --j)
        {
            t      = a[j];
            a[j]   = a[j+1];
            a[j+1] = t;
        }
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

    insertSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    return 0;
}
