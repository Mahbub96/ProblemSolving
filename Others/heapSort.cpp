
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void maxHeap(vector<int> &arr, int length)
{
    if (length == 0) // in case of list has only 1 value
        return;

    int parent = 0;

    if (length % 2 == 0)
        parent = length / 2 - 1;
    else
        parent = floor(length / 2);

    while (parent >= 0)
    {
        int tmpRoot = arr[parent];
        int right = -1;
        int left = arr[parent * 2 + 1];

        if (parent * 2 + 2 <= length)
            right = arr[parent * 2 + 2];
        // swap
        if (left >= right && left > tmpRoot)
            swap(arr[parent * 2 + 1], arr[parent]);
        else if (right >= left && right > tmpRoot)
            swap(arr[parent * 2 + 2], arr[parent]);

        parent -= 1;
    }
}

void heapSort(vector<int> &arr)
{
    int length = arr.size() - 1;

    while (length >= 0)
    {
        maxHeap(arr, length);
        swap(arr[0], arr[length]);
        length -= 1;
    }
}

int main()
{
    vector<int> arr;
    for (size_t i = 0; i < 10; i++)
    {
        arr.push_back(random() % 10);
    }

    heapSort(arr);
    for (size_t i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
