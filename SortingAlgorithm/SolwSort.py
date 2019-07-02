# coding=utf-8


def slowSort(array, start, end):
    if start >= end:
        return

    mid = (start + end) / 2
    slowSort(array, start, mid)
    slowSort(array, mid + 1, end)

    if array[mid] > array[end]:
        array[mid], array[end] = array[end], array[mid]

    slowSort(array, start, end - 1)


if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    start = 0
    end = len(a) - 1
    slowSort(a, start, end)
    print a
