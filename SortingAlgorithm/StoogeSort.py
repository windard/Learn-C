# coding=utf-8


def stoogeSort(array, start, end):
    if array[start] > array[end]:
        array[start], array[end] = array[end], array[start]
    if start + 1 == end:
        return

    split = (end - start + 1) / 3
    stoogeSort(array, start, end - split)
    stoogeSort(array, start + split, end)
    stoogeSort(array, start, end - split)


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    start = 0
    end = len(a) - 1
    stoogeSort(a, start, end)

    print a
