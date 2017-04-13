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
