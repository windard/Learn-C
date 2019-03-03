# coding=utf-8

import random


def bucket_sort(array):
    b = [0] * (max(array) + 1)
    result = []
    for i in array:
        b[i] += 1
    for key, value in enumerate(b):
        result.extend([key] * value)
    return result


if __name__ == '__main__':
    # a = [random.randint(1, 100000) for i in range(10000)]
    a = [10, 1, 23, 78, 11, 104, 65, 12, 23, 36, 3, 53]
    print a

    a = bucket_sort(a)
    print a
