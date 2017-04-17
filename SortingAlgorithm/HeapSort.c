#include "stdio.h"

#define N 15

void swap(int  &a, int  &b){
    int t = a;
    a = b;
    b = t;
}

// void swap(int* a, int* b) {
//     int temp = *b;
//     *b = *a;
//     *a = temp;
// }

// void MinHeapFixup(int  a[], int  i){
//     int     j, t;
//     t = a[i];
//     j = (i-1) / 2;
//     while(j >= 0 && i != 0){
//         if (a[j] <= t) break;

//         a[i] = a[j];
//         i = j;
//         j = (i-1) / 2;
//     }
//     a[i] = t;
// }

// void MinHeapAddNum(int  a[], int  n, int  nNum){
//     a[n] = nNum;
//     MinHeapFixup(a, n);
// }

// void MinHeapFixDown(int  a[], int  i, int  n){
//     int     j, t;
//     t = a[i];
//     j = 2*i +1;
//     while(j < n){
//         if(j+1 < n && a[j+1] < a[j])
//             j ++;
//         if(a[j] >= t)
//             break;
//         a[i] = a[j];
//         i = j;
//         j = 2*i + 1;
//     }
//     a[i] = t;
// }

// void MinHeapDelNum(int  a[], int  n){
//     swap(a[0], a[n-1]);
//     MinHeapFixDown(a, 0, n-1);
// }

// void MakeMinHeap(int  a[]){
//     int     i;
//     for (i = N / 2 -1; i >= 0; --i)
//     {
//         MinHeapFixDown(a, i, N);
//     }
// }

// void headSort(int  a[]){
//     int     i;
//     for (i = N / 2 -1; i >= 1; --i) {
//         MinHeapFixDown(a, i, N);
//     }
//     for (i = N-1; i > 0; --i) {
//         MinHeapFixDown(a, 0, i);
//         swap(a[i], a[0]);
//     }
// }

void maxHeapify(int  a[], int start, int  end) {
    int     dad = start;
    int     son = dad * 2 + 1;
    while(son <= end) {
        if (son+1 <= end && a[son] < a[son+1])
            son ++;
        if (a[dad] > a[son])
            return;
        swap(a[dad], a[son]);
        dad = son;
        son = dad * 2 + 1;
    }
}

void headSort(int  a[]){
    int     i;
    for (i = N / 2 -1; i >= 0; --i)
        maxHeapify(a, i, N-1);
    for (i = N - 1; i > 0; --i)
    {
        swap(a[0], a[i]);
        maxHeapify(a, 0, i-1);
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

    headSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    return 0;
}
