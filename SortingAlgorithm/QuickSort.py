# coding=utf-8


def quickSort(array):
    t = len(array) / 2
    while t:
        for i in xrange(t):
            for j in xrange(0, len(array), t):
                pass


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    quickSort(a)
    print a
