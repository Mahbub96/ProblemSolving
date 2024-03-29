# heap sort implimentation using python
import math
import random


def isSort(arr):
    i = 0
    size = len(arr)
    while(i < (size-1)):
        if arr[i] > arr[i+1]:
            return False
        i += 1
    return True


def maxHeap(arr, length):
    if(length == 0):  # in case of list has only 1 value
        return

    parent = int(math.ceil(length/2)-1)

    # if(length % 2 == 0):
    #     parent = int(length / 2 - 1)
    # else:
    #     parent = int(math.floor(length/2))

    while(parent >= 0):
        tmpRoot = arr[parent]
        right = -1
        left = arr[parent*2+1]

        if (parent*2+2 <= length):
            right = arr[parent*2+2]
        # swap
        if left >= right and left > tmpRoot:
            arr[parent*2+1], arr[parent] = arr[parent], arr[parent*2+1]
        elif right > left and right > tmpRoot:
            arr[parent*2+2], arr[parent] = arr[parent], arr[parent*2+2]

        parent -= 1


def heapSort(arr):
    length = len(arr)-1

    while(length >= 0):
        maxHeap(arr, length)
        arr[0], arr[length] = arr[length], arr[0]  # value swap
        length -= 1


arr = []
n = 9000
for i in range(n):
    arr.append(int(random.random()*n))

# print(arr)
print(isSort(arr))
heapSort(arr)
print(isSort(arr))
