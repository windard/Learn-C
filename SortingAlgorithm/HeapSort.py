# coding=utf-8


def heapSort(array):
    def maxHeapify(a, start, end):
        root = start
        while 1:
            child = 2 * root + 1
            if child > end:
                break
            if child+1 <= end and a[child+1] > a[child]:
                child += 1
            if a[child] > a[root]:
                a[child], a[root] = a[root], a[child]
                root = child
            else:
                break
                    
    for start in xrange(len(array) / 2 - 1, -1, -1):
        maxHeapify(array, start, len(array) - 1)

    for end in xrange(len(array) - 1, 0, -1):
        array[0], array[end] = array[end], array[0]
        maxHeapify(a, 0, end-1)

if __name__ == '__main__':
    a = [10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53]
    print a

    heapSort(a)
    print a
