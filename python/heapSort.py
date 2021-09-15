# heap sort implimentation using python
import math


def maxHeap(arr, length):
    if(length == 0):  # in case of list has only 1 value
        return

    parent = 0

    if(length % 2 == 0):
        parent = int(length / 2 - 1)
    else:
        parent = int(math.floor(length/2))

    while(parent >= 0):
        tmpRoot = arr[parent]
        right = -1
        left = arr[parent*2+1]

        if (parent*2+2 <= length):
            right = arr[parent*2+2]
        # swap
        if left >= right and left > tmpRoot:
            arr[parent*2+1], arr[parent] = arr[parent], arr[parent*2+1]
        elif right >= left and right > tmpRoot:
            arr[parent*2+2], arr[parent] = arr[parent], arr[parent*2+2]

        parent -= 1


def heapSort(arr):
    length = len(arr)-1

    while(length >= 0):
        maxHeap(arr, length)
        arr[0], arr[length] = arr[length], arr[0]  # value swap
        length -= 1


arr = [8, 6, 7, 3, 1, 2]

print(arr)
heapSort(arr)
print(arr)
