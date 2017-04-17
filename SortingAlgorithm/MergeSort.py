# coding=utf-8


# def merge_sort(a, b, start, end):
#     if start >= end:
#         return

#     mid = (start + end) / 2
#     merge_sort(a, b, start, mid)
#     merge_sort(a, b, mid+1, end)

#     k = m = start
#     n = mid
#     x = mid + 1
#     y = end

#     while (m <= n and x <= y):
#         if a[m] < a[x]:
#             b[k] = a[m]
#             m += 1
#         else:
#             b[k] = a[x]
#             x += 1
#         k += 1

#     while (m <= n):
#         b[k] = a[m]
#         k += 1
#         m += 1

#     while (x <= y):
#         b[k] = a[x]
#         k += 1
#         x += 1

#     for i in xrange(start, end+1):
#         a[i] = b[i]


# def mergeSort(array):
#     b = [0 for i in xrange(len(array))]
#     merge_sort(array, b, 0, len(array)-1)


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
