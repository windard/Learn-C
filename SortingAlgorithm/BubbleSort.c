#include "stdio.h"

#define N 15

// void bubbleSort(int a[]){
//     int         t;
//     for (int i = 0; i < N; ++i)
//     {
//         for (int j = 1; j < N - i; ++j)
//         {
//             if ( a[j-1] > a[j]) {
//                 t      = a[j];
//                 a[j]   = a[j-1];
//                 a[j-1] = t;
//             }
//         }
//     }
// }

// void bubbleSort(int a[]){
//     int         t,flag;
//     for (int i = 0; i < N; ++i)
//     {
//         flag = 1;
//         for (int j = 1; j < N - i; ++j)
//         {
//             if ( a[j-1] > a[j]) {
//                 t      = a[j];
//                 a[j]   = a[j-1];
//                 a[j-1] = t;
//                 flag = 0;
//             }
//         }
//         if (flag) break;
//     }
// }

void bubbleSort(int a[]){
    int         i, j, t, k, flag;

    flag = N;
    for (i = 0; i < N; ++i)
    {
        k = flag;
        flag = 0;
        for (j = 1; j < k; ++j)
        {
            if ( a[j-1] > a[j]) {
                t      = a[j];
                a[j]   = a[j-1];
                a[j-1] = t;
                flag = j;
            }
        }
        if (!flag) break;
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

    bubbleSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }
    return 0;
}
