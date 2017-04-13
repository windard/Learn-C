#include "stdio.h"

#define N 15

void shellSort(int a[]){
    int     i, j, t, g, k;
    for (g = N/2; g > 0; g /= 2)
    {
        for (i = 0; i < g; ++i)
        {
            for (j = i+g; j < N; j += g)
            {
                if (a[j] < a[j-g]){
                    t = a[j];
                    k = j - g;
                    while (k >= 0 && a[k] > t){
                        a[k+g] = a[k];
                        k -= g;
                    }
                    a[k+g] = t;
                }
            }
        }
    }
}

// void shellSort(int a[]){
//     int     j, g, t, k;
//     for (g = N/2; g > 0; g /= 2)
//     {
//         for (j = g; j < N; ++j)
//         {
//             if (a[j] < a[j-g]){
//                 t = a[j];
//                 k = j - g;
//                 while (k >= 0 && a[k] > t){
//                     a[k+g] = a[k];
//                     k     -= g;
//                 }
//                 a[k+g] = t;
//             }
//         }
//     }
// }

// void shellSort(int a[]){
//     int     i, j, g, t;
//     for (g = N/2; g > 0; g /= 2)
//     {
//         for (i = g; i < N; ++i)
//         {
//             for (j = i-g; j >= 0 && a[j] > a[j+g]; j -= g)
//             {
//                 t = a[j];
//                 a[j] = a[j+g];
//                 a[j+g] = t;
//             }
//         }
//     }
// }

int main(int argc, char const *argv[])
{
    int         a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

    printf("Origin : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    shellSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    return 0;
}
