# coding=utf-8


# def shellSort(array):
#     g = len(array) / 2
#     while g:
#         for i in xrange(g):
#             for j in xrange(i+g, len(array), g):
#                 if array[j] < array[j-g]:
#                     t = array[j]
#                     for k in xrange(j-g, -1, -g):
#                         if array[k] < t:
#                             array[k+g] = t
#                             break
#                         array[k+g] = array[k]
#                     else:
#                         array[i] = t
#         g = g / 2


# def shellSort(array):
#     g = len(array) / 2
#     while g:
#         for j in xrange(g, len(array)):
#             if array[j] < array[j-g]:
#                 t = array[j]
#                 for k in xrange(j-g, -1, -g):
#                     if array[k] < t:
#                         array[k+g] = t
#                         break
#                     array[k+g] = array[k]
#                 else:
#                     array[j-g] = t
#         g = g / 2


# def shellSort(array):
#     g = len(array) / 2
#     while g:
#         for i in xrange(g, len(array)):
#             for j in xrange(i-g, -1, -g):
#                 if a[j] < a[j+g]:
#                     break
#                 a[j], a[j+g] = a[j+g], a[j]
#         g = g / 2


def shellSort(array):
    count = len(array)
    step = 2
    group = count / step
    while group:
        for i in xrange(group):
            j = i + group
            while j < count:
                k = j - group
                key = array[j]
                while k >= 0:
                    if array[k] > key:
                        array[k+group] = array[k]
                        array[k] = key
                    k -= group
                j += group
        group /= step

if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    shellSort(a)
    print a
