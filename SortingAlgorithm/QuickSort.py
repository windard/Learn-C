# coding=utf-8


def quick_sort(array, left, right):
    if left >= right:
        return
    key = array[left]
    low = left
    high = right

    while left < right:
        while left < right and array[right] >= key:
            right -= 1
        array[left] = array[right]
        while left < right and array[left] <= key:
            left += 1
        array[right] = array[left]
    array[right] = key
    quick_sort(array, low, left-1)
    quick_sort(array, left+1, high)


def quickSort(array):
    quick_sort(array, 0, len(array)-1)


# def quickSort(a):

#     return a if len(a) <= 1 else quickSort([x for x in a[1:] if x < a[0]]) + [a[0]] + quickSort([x for x in a[1:] if x >= a[0]])


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    quickSort(a)

    print a

    # quickSort = lambda a: a if len(a) <= 1 else quickSort([x for x in a[1:] if x < a[0]]) + [a[0]] + quickSort([x for x in a[1:] if x >= a[0]])

    # print quickSort(a)
