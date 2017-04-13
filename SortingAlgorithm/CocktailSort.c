#include "stdio.h"

#define N 15

// void cocktailSort(int a[]){
//     int     i, j, t, flag;

//     do
//     {
//         flag = 0;

//         for (i = 0; i < N - 1; ++i)
//         {
//             if (a[i] > a[i+1]) {
//                 t = a[i];
//                 a[i] = a[i+1];
//                 a[i+1] = t;
//                 flag = 1;
//             }
//         }

//         for (j = N -1; j > 0; --j)
//         {
//             if (a[j] < a[j-1]) {
//                 t = a[j];
//                 a[j] = a[j-1];
//                 a[j-1] = t;
//                 flag = 1;
//             }
//         }
//     }while(flag);
// }

void cocktailSort(int a[]){
    int     i, j, t, flag, n;

    n = 0;
    do
    {
        flag = 0;

        for (i = n; i < N - n -1; ++i)
        {
            if (a[i] > a[i+1]) {
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                flag = 1;
            }
        }

        for (j = N - n -1; j > n; --j)
        {
            if (a[j] < a[j-1]) {
                t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
                flag = 1;
            }
        }

        n += 1;
    }while(flag);
}

int main(int argc, char const *argv[])
{
    int         a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

    printf("Origin : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    cocktailSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    return 0;
}
