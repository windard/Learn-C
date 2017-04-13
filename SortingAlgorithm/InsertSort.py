# coding=utf-8


# def insertSort(array):
#     for i in xrange(len(array)):
#         for j in xrange(0, i):
#             if array[j] > array[i]:
#                 t = array[i]
#                 for z in xrange(i, j, -1):
#                     array[z] = array[z-1]
#                 array[j] = t


# def insertSort(array):
#     for i in xrange(1, len(array)):
#         for j in xrange(i, 0, -1):
#             if array[j] < array[j-1]:
#                 array[j], array[j-1] = array[j-1], array[j]

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
