#include <iostream>

using namespace std;

void sorting(int a[], int n)
{
    int numbers = 0;
    for (int i = 0; i < n; i++)
    {
        // Track number of elements swapped during a single array traversal
        int numberOfSwaps = 0;

        for (int j = 0; j < n - 1; j++)
        {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
            }
        }

        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0)
        {
            break;
        }
        numbers += numberOfSwaps;
    }

    cout << "Array is sorted in " << numbers << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    sorting(arr, n);
    return 0;
}