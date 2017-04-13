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
