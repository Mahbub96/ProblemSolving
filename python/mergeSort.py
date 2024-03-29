import random  # for input random value in list form driver


def isSort(arr):
    i = 0
    size = len(arr)
    while(i < (size-1)):
        if arr[i] > arr[i+1]:
            return False
        i += 1
    return True


def merge(a, lb, mid, ub):
    i, j, k = lb, mid+1, ub
    temp = []
    while(i <= mid and j <= ub):
        if(a[i] <= a[j]):
            temp.append(a[i])
            i += 1
        else:
            temp.append(a[j])
            j += 1
    while(i <= mid):
        temp.append(a[i])
        i += 1
    while(j <= ub):
        temp.append(a[j])
        j += 1

    i = lb
    j = 0
    while(i <= ub):
        a[i] = temp[j]
        i += 1
        j += 1


def mergeSort(arr, lb, ub):

    if(lb < ub):
        mid = int((lb+ub)/2)
        mergeSort(arr, lb, mid)
        mergeSort(arr, mid+1, ub)
        merge(arr, lb, mid, ub)


# Driver file

arr = []
n = 10000000
for i in range(n):
    arr.append(int(random.random()*n))


print(isSort(arr))
mergeSort(arr, 0, len(arr)-1)
print(isSort(arr))
