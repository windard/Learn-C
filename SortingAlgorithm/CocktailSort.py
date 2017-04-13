# coding=utf-8


# def cocktailSort(array):
#     while 1:
#         flag = False
#         for i in xrange(len(array)-1):
#             if array[i] > array[i+1]:
#                 array[i], array[i+1] = array[i+1], array[i]
#                 flag = True
#         for j in xrange(len(array)-1, 0, -1):
#             if array[j] < array[j-1]:
#                 array[j], array[j-1] = array[j-1], array[j]
#                 flag = True
#         if not flag:
#             break


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
