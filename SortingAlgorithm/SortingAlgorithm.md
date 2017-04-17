## 排序算法

### 冒泡排序

以排序为递增数组为例，将待排序的相邻数据元素两两比较，若为递减，则交换两元素。当从前往后依次扫描比较之后，最大的数会被放在最后一个位置，这个过程就被称为一次排序。

第二次排序则只需到倒数第二个位置就可以结束，扫描结束时，次大值被放在倒数第二个位置。

这个过程重复进行，直到所有待排数据按从小到大排列。由于在排序过程中，小的数像气泡一样逐渐上升，而大的数则逐渐下沉，所以形象的将这种排序算法称为冒泡排序。

```
#include "stdio.h"

#define N 15

int main(int argc, char const *argv[])
{
	int			t;
	int 		a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

	printf("Origin : ");
	for (int i = 0; i < N; ++i)
	{
		printf("%4d", a[i]);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j < N - i; ++j)
		{
			if ( a[j-1] > a[j]) {
				t      = a[j];
				a[j]   = a[j-1];
				a[j-1] = t;
			}
		}
	}

	printf("\nSorted : ");
	for (int i = 0; i < N; ++i)
	{
		printf("%4d", a[i]);
	}
	return 0;
}

```

```
original :   10   1  23  -5   0  78  11 104  65  -1  12  23  36   3  53
Sorted   :   -5  -1   0   1   3  10  11  12  23  23  36  53  65  78 104
```

一点点小小的改进，如果在某一次的扫描过程中没有发生替换，则说明数组已经完成排序，无需继续扫描。

```
#include "stdio.h"

#define N 15

int main(int argc, char const *argv[])
{
	int			t,flag;
	int 		a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

	printf("Origin : ");
	for (int i = 0; i < N; ++i)
	{
		printf("%4d", a[i]);
	}

	for (int i = 0; i < N; ++i)
	{
        flag = 1;
		for (int j = 1; j < N - i; ++j)
		{
			if ( a[j-1] > a[j]) {
				t      = a[j];
				a[j]   = a[j-1];
				a[j-1] = t;
                flag = 0;
			}
		}
        if (flag) break;
	}

	printf("\nSorted : ");
	for (int i = 0; i < N; ++i)
	{
		printf("%4d", a[i]);
	}
	return 0;
}

```

最后一次的改进

```
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

```

标准的冒泡排序的逻辑复杂度为 N*(N+1)/2

Python 版的冒泡排序

```
# coding=utf-8


def BubbleSort(array):
    for i in xrange(len(array)):
        for j in xrange(1, len(array) - i):
            if array[j-1] > array[j]:
                array[j-1], array[j] = array[j], array[j-1]

if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    BubbleSort(a)
    print a

```

### 直接插入排序

以排序为递增数组为例，每次将一个待排序的记录，按其大小插入到前面已经排好序的子序列中的适当位置。

子序列从数组第一个元素开始，直至将最后一个元素插入子序列。

```
#include "stdio.h"

#define N 15

void insertSort(int a[]){
    int     i, j, t, k;
    for (i = 1; i < N; ++i)
    {
        for (j = i-1; j >= 0; --j)
        {
            if (a[j] < a[i]) break;
        }

        if (j != i-1) {
            t = a[i];
            for (k = i-1; k > j; --k)
            {
                a[k+1] = a[k];
            }
            a[k+1] = t;
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

```

稍作改进，将搜索和后移合并。

```
void insertSort(int a[]){
    int     i, j, t;
    for (i = 1; i < N; ++i)
    {
        if (a[i] < a[i-1]) {
            t = a[i];
            for (j = i-1; j >= 0 && a[j] > t; --j) {
                a[j+1] = a[j];
            }
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

```

还能再次改进，将数据交换代替数据后移。

```
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

```

标准的插入排序的逻辑复杂度为 

Python 版的插入排序

```
# coding=utf-8


def insertSort(array):
    for i in xrange(len(array)):
        for j in xrange(0, i):
            if array[j] > array[i]:
                t = array[i]
                for z in xrange(i, j, -1):
                    array[z] = array[z-1]
                array[j] = t


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    insertSort(a)
    print a

```

或者这样

```
def insertSort(array):
    for i in xrange(1, len(array)):
        t = array[i]
        for j in xrange(i, -1, -1):
            if array[j] < t:
                array[j+1] = t
                break
            array[j] = array[j-1]
        else:
            array[0] = t

if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    insertSort(a)
    print a
```

### 希尔排序

希尔排序的实质就是分组插入排序，改方法又称缩小增量排序，因 DL. Shell 于 1959 年提出而得名。

先按照一定的间隔将序列分组，在每一个分组中采用直接插入排序进行排序。

然后缩减间隔，再次采用直接插入排序，直至间隔为 1，即完成排序。

```
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

```

改进的希尔排序

```
void shellSort(int a[]){
    int     j, g, t, k;
    for (g = N/2; g > 0; g /= 2)
    {
        for (j = g; j < N; ++j)
        {
            if (a[j] < a[j-g]){
                t = a[j];
                k = j - g;
                while (k >= 0 && a[k] > t){
                    a[k+g] = a[k];
                    k     -= g;
                }
                a[k+g] = t;
            }
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

    shellSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    return 0;
}

```

当然，还可以进一步的改进

```
void shellSort(int a[]){
    int     i, j, g, t;
    for (g = N/2; g > 0; g /= 2)
    {
        for (i = g; i < N; ++i)
        {
            for (j = i-g; j >= 0 && a[j] > a[j+g]; j -= g)
            {
                t = a[j];
                a[j] = a[j+g];
                a[j+g] = t;
            }
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

    shellSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    return 0;
}

```

标准的希尔排序的逻辑复杂度为

Python 版的希尔排序

```
# coding=utf-8


def shellSort(array):
    g = len(array) / 2
    while g:
        for i in xrange(g):
            for j in xrange(i+g, len(array), g):
                if array[j] < array[j-g]:
                    t = array[j]
                    for k in xrange(j-g, -1, -g):
                        if array[k] < t:
                            array[k+g] = t
                            break
                        array[k+g] = array[k]
                    else:
                        array[i] = t
        g = g / 2

if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    shellSort(a)
    print a

```

还可以更简单

```
# coding=utf-8


def shellSort(array):
    g = len(array) / 2
    while g:
        for j in xrange(g, len(array)):
            if array[j] < array[j-g]:
                t = array[j]
                for k in xrange(j-g, -1, -g):
                    if array[k] < t:
                        array[k+g] = t
                        break
                    array[k+g] = array[k]
                else:
                    array[j-g] = t
        g = g / 2


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    shellSort(a)
    print a

```

或者更简单

```
# coding=utf-8


def shellSort(array):
    g = len(array) / 2
    while g:
        for i in xrange(g, len(array)):
            for j in xrange(i-g, -1, -g):
                if a[j] < a[j+g]:
                    break
                a[j], a[j+g] = a[j+g], a[j]
        g = g / 2


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    shellSort(a)
    print a

```

### 直接选择排序

以排序为递增数组为例，从 a[0] ~ a[N] 中选出最小的数，将它与第 0 个数元素交换。

然后从 a[1] ~ a[N] 中选出最小的数，将它与第 1 个元素交换。

这个过程重复进行，直到完成排序。

```
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

```

直接选择排序的逻辑复杂度为 

Python 版的直接选择排序

```
# coding=utf-8


def selectSort(array):
    for i in xrange(len(array)):
        t = i
        for j in xrange(i+1, len(array)):
            if array[j] < array[t]:
                t = j
        array[i], array[t] = array[t], array[i]


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    selectSort(a)
    print a

```

### 归并排序

归并排序是采用分治思想的一种典型应用。

先将数组分成两组，然后将每一个小组各自再分成两组，依次类推，当分出来的小组只有一个数据时，即可用认为该小组已经达到了有序，再合并相邻的两个小组。

在合并两个小组的时候，其实是使用了另一个数组的空间，将合并后的结果放入另一个数组空间中。

因为所有的递归都可以被写成迭代的形式，所以归并排序也有两种形式

迭代版

```
#include "stdio.h"

#define N 15

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

    for (i = 0; i < N; ++i)
    {
        a[i] = b[i];
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

```

递归版

```
#include "stdio.h"

#define N 15

void merge_sort(int a[], int b[], int start, int end){
    if (start >= end)
        return;

    int     len = end - start;
    int     mid = (len >> 1) + start;
    int     start1 = start;
    int     end1 = mid;
    int     start2 = mid + 1;
    int     end2 = end;
    merge_sort(a, b, start1, end1);
    merge_sort(a, b, start2, end2);

    int     k = start;
    while(start1 <= end1 && start2 <= end2)
        b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
    while(start1 <= end1)
        b[k++] = a[start1++];
    while(start2 <= end2)
        b[k++] = a[start2++];

    for (k = start; k <= end; k++)
        a[k] = b[k];
}

void mergeSort(int a[]){
    int b[N];
    merge_sort(a, b, 0, N-1);
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

```

间接一点的写法

```
#include "stdio.h"

#define N 15

void merge_sort(int a[], int b[], int start, int end){
    if (start < end){
        int mid = (start + end) / 2;
        merge_sort(a, b, start, mid);
        merge_sort(a, b, mid+1, end);

        int i = start;
        int j = mid + 1;
        int m = mid;
        int n = end;

        int k = start;

        while(i <= m && j <= n)
            b[k++] = a[i] < a[j] ? a[i++] : a[j++];
        while(i <= m)
            b[k++] = a[i++];
        while(j <= n)
            b[k++] = a[j++];

        for (i = start; i <= end; ++i)
            a[i] = b[i];

    }
}

void mergeSort(int a[]){
    int b[N];
    merge_sort(a, b, 0, N-1);
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

```

归并排序的逻辑复杂度为

Python 版的归并排序

迭代版

```
# coding=utf-8


def mergeSort(array):
    b = [0 for i in xrange(len(array))]

    i = 1
    while 1:
        if i >= len(array):
            break

        for j in xrange(0, len(b), 2*i):

            k = m = j
            n = x = j + i if j + i < len(b) else len(b)
            y = j + 2*i if j + 2*i < len(b) else len(b)

            while (m < n and x < y):
                if array[m] < array[x]:
                    b[k] = array[m]
                    m += 1
                else:
                    b[k] = array[x]
                    x += 1
                k += 1

            while (m < n):
                b[k] = array[m]
                k += 1
                m += 1

            while (x < y):
                b[k] = array[x]
                k += 1
                x += 1

        for j in xrange(len(b)):
            array[j] = b[j]

        i *= 2


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    mergeSort(a)
    print a

```

递归版

```
# coding=utf-8


def merge_sort(a, b, start, end):
    if start >= end:
        return

    mid = (start + end) / 2
    merge_sort(a, b, start, mid)
    merge_sort(a, b, mid+1, end)

    k = m = start
    n = mid
    x = mid + 1
    y = end

    while (m <= n and x <= y):
        if a[m] < a[x]:
            b[k] = a[m]
            m += 1
        else:
            b[k] = a[x]
            x += 1
        k += 1

    while (m <= n):
        b[k] = a[m]
        k += 1
        m += 1

    while (x <= y):
        b[k] = a[x]
        k += 1
        x += 1

    for i in xrange(start, end+1):
        a[i] = b[i]


def mergeSort(array):
    b = [0 for i in xrange(len(array))]
    merge_sort(array, b, 0, len(array)-1)


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    mergeSort(a)
    print a

```

Python 无论是递归版还是迭代版都非常的丑陋，简直就是 C 语言的完全重写，没意思。。。

### 快速排序

快速排序也是采用分治思想的一种排序算法。

以排序为递增数组为例，将数组分割为独立的两部分，第一部分的所有数据比第二部分的所有数据都要小。

然后再按此方法对两部分数据分别递归进行快速排序。

即首先从数列中取出一个数作为基准数，比它大的数放在它的右边，比它小或者等于的数全放在它的左边，如此重复，直到个区间只剩下一个数。

可以看出快速排序算法和分治排序算法还是有很多的相似之处，快速排序算法既可以采用类似于分治排序算法的重新开辟存储空间的办法，也可以采用在原来的存储空间的办法。

每一种的算法都可以分迭代法和递归法，而快速迭代算法的迭代实现的话都需要使用栈，或者类似于栈的结构。

原地址快排

迭代法

```
#include "stdio.h"

#define N 15

typedef struct _Range
{
    int start, end;
}Range;

Range newRange(int s, int t){
    Range r;
    r.start = s;
    r.end = t;
    return r;
}

void swap(int  *x, int  *y){
    int     t = *x;
    *x = *y;
    *y = t;
}

void quickSort(int  a[]){
    int     pivotIndex, pivotValue;
    int     i, j, t, r, n;
    n = 0;
    Range   m[N];
    m[n++] = newRange(0, N-1);
    while (n) {
        Range range = m[--n];
        if (range.start >= range.end) continue;
        int start = range.start;
        int end = range.end;

        pivotValue = a[end];
        pivotIndex = start;
        for (i = start; i < end; ++i)
        {
            if (a[i] <= pivotValue) {
                swap(&a[i], &a[pivotIndex]);
                pivotIndex = pivotIndex + 1;
            }
        }
        swap(&a[end], &a[pivotIndex]);
        
        m[n++] = newRange(start, pivotIndex-1);
        m[n++] = newRange(pivotIndex+1, end);
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

    quickSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    return 0;
}

```

另一种迭代法

```
#include "stdio.h"

#define N 15

void swap(int  *x, int  *y){
    int     t = *x;
    *x = *y;
    *y = t;
}

void quickSort(int  a[]){
    int     s = 0;
    int     stack[N*4];
    int     left, right;
    int     start, end, mid;

    stack[s++] = 0;
    stack[s++] = N -1;

    while(s){
        end = stack[--s];
        start = stack[--s];

        if (start >= end) continue;

        left = start;
        mid = a[end];
        right = end;

        while (left < right) {
            while(a[left] < mid && left < right)
                left ++;
            while(a[right] >= mid && left < right)
                right --;
            swap(&a[left], &a[right]);
        }

        if (a[left] >= a[end]){
            swap(&a[left], &a[end]);
        }

        stack[s++] = start;
        stack[s++] = left-1;
        stack[s++] = left+1;
        stack[s++] = end;
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

    quickSort(a);

    printf("\nSorted : ");
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", a[i]);
    }

    return 0;
}

```

递归法

```
#include "stdio.h"

#define N 15

void quick_sort(int a[], int left, int right) {
    if (left >= right){
        return;
    }
    int     pivotIndex, pivotValue;
    int     i, t;
    pivotValue = a[right];
    pivotIndex = 0;
    for (i = 0; i < right; ++i)
    {
        if (a[i] <= pivotValue){
            t = a[i];
            a[i] = a[pivotIndex];
            a[pivotIndex] = t;
            pivotIndex += 1;
        }
    }
    t = a[right];
    a[right] = a[pivotIndex];
    a[pivotIndex] = t;

    quick_sort(a, left, pivotIndex-1);
    quick_sort(a, pivotIndex+1, right);
}

void quickSort(int  a[]) {
    quick_sort(a, 0, N-1);
}

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

```

另一种迭代法

```
#include "stdio.h"

#define N 15

void quick_sort(int a[], int start, int end){
    if (start >= end) return;

    int     t;
    int     mid = a[end];
    int     left = start, right = end -1;

    while (left < right) {
        while(a[left] < mid && left < right)
            left ++;
        while(a[right] >= mid && left < right)
            right --;
        t = a[left];
        a[left] = a[right];
        a[right] = t;
    }

    if (a[left] >= a[end]) {
        t = a[left];
        a[left] = a[end];
        a[end] = t;
    }

    quick_sort(a, start, left-1);
    quick_sort(a, left+1, end);

}

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

```

还有一种迭代法

```
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

```

快速排序算法的逻辑复杂度为

Python 版快速排序算法

```
# coding=utf-8


def quickSort(a):

    return a if len(a) <=1 else quickSort([x for x in a[1:] if x < a[0]]) + [a[0]] + quickSort([x for x in a[1:] if x >= a[0]])


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    print quickSort(a)
```

### 鸡尾酒排序

鸡尾酒排序也被称为双向冒泡排序，或破浪排序。

它与冒泡排序类型，只不过冒泡排序只从左往右冒泡，而鸡尾酒排序从左往右冒泡，然后从右往左冒泡，双向冒泡排序。

```
#include "stdio.h"

#define N 15

void cocktailSort(int a[]){
    int     i, j, t, flag;

    do
    {
        flag = 0;

        for (i = 0; i < N - 1; ++i)
        {
            if (a[i] > a[i+1]) {
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                flag = 1;
            }
        }

        for (j = N -1; j > 0; --j)
        {
            if (a[j] < a[j-1]) {
                t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
                flag = 1;
            }
        }
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

```

还可以更简单一点

```
#include "stdio.h"

#define N 15

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

```

鸡尾酒排序算法的逻辑复杂度为

Python 版的鸡尾酒排序算法

```
# coding=utf-8


def cocktailSort(array):
    while 1:
        flag = False
        for i in xrange(len(array)-1):
            if array[i] > array[i+1]:
                array[i], array[i+1] = array[i+1], array[i]
                flag = True
        for j in xrange(len(array)-1, 0, -1):
            if array[j] < array[j-1]:
                array[j], array[j-1] = array[j-1], array[j]
                flag = True
        if not flag:
            break


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    cocktailSort(a)
    print a

```

或者这样

```
# coding=utf-8


def cocktailSort(array):
    n = 0
    while 1:
        flag = False
        for i in xrange(len(array)-1-n, n):
            if array[i] > array[i+1]:
                array[i], array[i+1] = array[i+1], array[i]
                flag = True
        for j in xrange(len(array)-1-n, n, -1):
            if array[j] < array[j-1]:
                array[j], array[j-1] = array[j-1], array[j]
                flag = True

        n += 1

        if not flag:
            break


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    cocktailSort(a)
    print a

```

### 堆排序

堆排序和归并排序，快速排序一样都是时间复杂度为 O(N*logN) 的几种常见排序方法。

堆是完全二叉树，或者是近似完全二叉树。

递增排序

```
#include "stdio.h"

#define N 15

void swap(int  &a, int  &b){
    int t = a;
    a = b;
    b = t;
}

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

```

递减排序

```
#include "stdio.h"

#define N 15

void swap(int  &a, int  &b){
    int t = a;
    a = b;
    b = t;
}

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void MinHeapFixup(int  a[], int  i){
    int     j, t;
    t = a[i];
    j = (i-1) / 2;
    while(j >= 0 && i != 0){
        if (a[j] <= t) break;

        a[i] = a[j];
        i = j;
        j = (i-1) / 2;
    }
    a[i] = t;
}

void MinHeapAddNum(int  a[], int  n, int  nNum){
    a[n] = nNum;
    MinHeapFixup(a, n);
}

void MinHeapFixDown(int  a[], int  i, int  n){
    int     j, t;
    t = a[i];
    j = 2*i +1;
    while(j < n){
        if(j+1 < n && a[j+1] < a[j])
            j ++;
        if(a[j] >= t)
            break;
        a[i] = a[j];
        i = j;
        j = 2*i + 1;
    }
    a[i] = t;
}

void MinHeapDelNum(int  a[], int  n){
    swap(a[0], a[n-1]);
    MinHeapFixDown(a, 0, n-1);
}

void MakeMinHeap(int  a[]){
    int     i;
    for (i = N / 2 -1; i >= 0; --i)
    {
        MinHeapFixDown(a, i, N);
    }
}

void headSort(int  a[]){
    int     i;
    for (i = N / 2 -1; i >= 1; --i) {
        MinHeapFixDown(a, i, N);
    }
    for (i = N-1; i > 0; --i) {
        MinHeapFixDown(a, 0, i);
        swap(a[i], a[0]);
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

```

堆排序算法的逻辑复杂度为

Python 版的推排序算法

```
# coding=utf-8


def heapSort(array):
    def maxHeapify(a, start, end):
        root = start
        while 1:
            child = 2 * root + 1
            if child > end:
                break
            if child+1 <= end and a[child+1] > a[child]:
                child += 1
            if a[child] > a[root]:
                a[child], a[root] = a[root], a[child]
                root = child
            else:
                break
                    
    for start in xrange(len(array) / 2 - 1, -1, -1):
        maxHeapify(array, start, len(array) - 1)

    for end in xrange(len(array) - 1, 0, -1):
        array[0], array[end] = array[end], array[0]
        maxHeapify(a, 0, end-1)

if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    heapSort(a)
    print a

```