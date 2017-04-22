# coding=utf-8


def quickSort(a):

    return a if len(a) <= 1 else quickSort([x for x in a[1:] if x < a[0]]) + [a[0]] + quickSort([x for x in a[1:] if x >= a[0]])


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    quickSort = lambda a: a if len(a) <= 1 else quickSort([x for x in a[1:] if x < a[0]]) + [a[0]] + quickSort([x for x in a[1:] if x >= a[0]])

    print quickSort(a)
