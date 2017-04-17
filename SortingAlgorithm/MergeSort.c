#include "stdio.h"

#define N 15

// void merge_sort(int a[], int b[], int start, int end){
//     if (start >= end)
//         return;

//     int     len = end - start;
//     int     mid = (len >> 1) + start;
//     int     start1 = start;
//     int     end1 = mid;
//     int     start2 = mid + 1;
//     int     end2 = end;
//     merge_sort(a, b, start1, end1);
//     merge_sort(a, b, start2, end2);

//     int     k = start;
//     while(start1 <= end1 && start2 <= end2)
//         b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
//     while(start1 <= end1)
//         b[k++] = a[start1++];
//     while(start2 <= end2)
//         b[k++] = a[start2++];

//     for (k = start; k <= end; k++)
//         a[k] = b[k];
// }

// void merge_sort(int a[], int b[], int start, int end){
//     if (start < end){
//         int mid = (start + end) / 2;
//         merge_sort(a, b, start, mid);
//         merge_sort(a, b, mid+1, end);

//         int i = start;
//         int j = mid + 1;
//         int m = mid;
//         int n = end;

//         int k = start;

//         while(i <= m && j <= n)
//             b[k++] = a[i] < a[j] ? a[i++] : a[j++];
//         while(i <= m)
//             b[k++] = a[i++];
//         while(j <= n)
//             b[k++] = a[j++];

//         for (i = start; i <= end; ++i)
//             a[i] = b[i];

//     }
// }

// void mergeSort(int a[]){
//     int b[N];
//     merge_sort(a, b, 0, N-1);
// }

void mergeSort(int a[]){
    int     b[N];
    int     i, j, m, n, x, y, t;

    for (i = 1; i < N; i *= 2)
    {
        for (j = 0; j < N; j += 2*i)
        {
            x = n = j + i < N ? j + i : N;
            y = j + i*2 < N ? j + i*2 : N;

            t = m = j;

            while(m < n && x < y)
                b[t++] = a[m] < a[x] ? a[m++] : a[x++];
            while(m < n)
                b[t++] = a[m++];
            while(x < y)
                b[t++] = a[x++];
        }

        for (j = 0; j < N; ++j)
        {
            a[j] = b[j];
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

    mergeSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    return 0;
}
