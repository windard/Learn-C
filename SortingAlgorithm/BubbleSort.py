# coding=utf-8

import random

def BubbleSort(array):
    for i in xrange(len(array)):
        for j in xrange(1, len(array) - i):
            if array[j-1] > array[j]:
                array[j-1], array[j] = array[j], array[j-1]


def bubble_sort(array):
    unsorted_array_index = len(array) - 1
    sorted_flag = False
    while not sorted_flag:
        sorted_flag = True
        for i in range(unsorted_array_index):
            if array[i] > array[i+1]:
                sorted_flag = False
                array[i], array[i+1] = array[i+1], array[i]
        unsorted_array_index = unsorted_array_index - 1


if __name__ == '__main__':
    a = [random.randint(1, 100000) for i in range(10000)]
    # a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    BubbleSort(a)
    print a
