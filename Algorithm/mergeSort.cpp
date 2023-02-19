#include <iostream>

using namespace std;

void mergeSort(int *arr, int len)
{
}

int main()
{

    int arr[] = {64, 25, 12, 22, 11};

    mergeSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ",";
    }
    return 0;
}
