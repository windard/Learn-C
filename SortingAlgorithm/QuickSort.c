#include "stdio.h"

#define N 15

void quick_sort(int a[], int l, int r){
    if (l < r){
        int     i = l;
        int     j = r;
        int     x = a[l];

        while(i < j){
            while(i < j && a[j] >= x)
                j--;
            if(i < j)
                a[i++] = a[j];
            while(i < j && a[i] < x)
                i++;
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = x;

        quick_sort(a, l, i-1);
        quick_sort(a, i+1, r);
    }
}

void quickSort(int  a[]){
    quick_sort(a, 0, N-1);
}

// void swap(int  *x, int  *y){
//     int     t = *x;
//     *x = *y;
//     *y = t;
// }

// void quickSort(int  a[]){
//     int     s = 0;
//     int     stack[N*4];
//     int     left, right;
//     int     start, end, mid;

//     stack[s++] = 0;
//     stack[s++] = N -1;

//     while(s){
//         end = stack[--s];
//         start = stack[--s];

//         if (start >= end) continue;

//         left = start;
//         mid = a[end];
//         right = end;

//         while (left < right) {
//             while(a[left] < mid && left < right)
//                 left ++;
//             while(a[right] >= mid && left < right)
//                 right --;
//             swap(&a[left], &a[right]);
//         }

//         if (a[left] >= a[end]){
//             swap(&a[left], &a[end]);
//         }

//         stack[s++] = start;
//         stack[s++] = left-1;
//         stack[s++] = left+1;
//         stack[s++] = end;
//     }
// }

// void quick_sort(int a[], int start, int end){
//     if (start >= end) return;

//     int     t;
//     int     mid = a[end];
//     int     left = start, right = end -1;

//     while (left < right) {
//         while(a[left] < mid && left < right)
//             left ++;
//         while(a[right] >= mid && left < right)
//             right --;
//         t = a[left];
//         a[left] = a[right];
//         a[right] = t;
//     }

//     if (a[left] >= a[end]) {
//         t = a[left];
//         a[left] = a[end];
//         a[end] = t;
//     }

//     quick_sort(a, start, left-1);
//     quick_sort(a, left+1, end);

// }

// void quickSort(int  a[]){
//     quick_sort(a, 0, N-1);
// }

// typedef struct _Range
// {
//     int start, end;
// }Range;

// Range newRange(int s, int t){
//     Range r;
//     r.start = s;
//     r.end = t;
//     return r;
// }

// void swap(int  *x, int  *y){
//     int     t = *x;
//     *x = *y;
//     *y = t;
// }

// void quickSort(int  a[]){
//     int     pivotIndex, pivotValue;
//     int     i, j, t, r, n;
//     n = 0;
//     Range   m[N];
//     m[n++] = newRange(0, N-1);
//     while (n) {
//         Range range = m[--n];
//         if (range.start >= range.end) continue;
//         int start = range.start;
//         int end = range.end;

//         pivotValue = a[end];
//         pivotIndex = start;
//         for (i = start; i < end; ++i)
//         {
//             if (a[i] <= pivotValue) {
//                 swap(&a[i], &a[pivotIndex]);
//                 pivotIndex = pivotIndex + 1;
//             }
//         }
//         swap(&a[end], &a[pivotIndex]);
        
//         m[n++] = newRange(start, pivotIndex-1);
//         m[n++] = newRange(pivotIndex+1, end);
//     }
// }

// void quick_sort(int a[], int left, int right) {
//     if (left >= right){
//         return;
//     }
//     int     pivotIndex, pivotValue;
//     int     i, t;
//     pivotValue = a[right];
//     pivotIndex = 0;
//     for (i = 0; i < right; ++i)
//     {
//         if (a[i] <= pivotValue){
//             t = a[i];
//             a[i] = a[pivotIndex];
//             a[pivotIndex] = t;
//             pivotIndex += 1;
//         }
//     }
//     t = a[right];
//     a[right] = a[pivotIndex];
//     a[pivotIndex] = t;

//     quick_sort(a, left, pivotIndex-1);
//     quick_sort(a, pivotIndex+1, right);
// }

// void quickSort(int  a[]) {
//     quick_sort(a, 0, N-1);
// }

int main(int argc, char const *argv[])
{
    int         a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

    printf("Origin : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    quickSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    return 0;
}
