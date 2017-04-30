# coding=utf-8

import math


# def radixSort(array, radix=10):
#     k = int(math.ceil(math.log(max(array), radix)))
#     bucket = [[] for i in xrange(radix)]

#     for i in xrange(1, k+1):
#         for j in array:
#             bucket[j/(radix**(i-1)) % (radix**i)].append(j)
#         del array[:]
#         for z in bucket:
#             array += z
#             del z[:]
#     return array

import math


def radixSort(a, radix=10):
    """a为整数列表， radix为基数"""
    K = int(math.ceil(math.log(max(a), radix))) # 用K位数可表示任意整数
    bucket = [[] for i in range(radix)] # 不能用 [[]]*radix
    for i in range(1, K+1): # K次循环
        for val in a:
            bucket[val%(radix**i)/(radix**(i-1))].append(val) # 析取整数第K位数字 （从低到高）
        del a[:]
        for each in bucket:
            a.extend(each) # 桶合并
        bucket = [[] for i in range(radix)]


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    radixSort(a)

    print a
