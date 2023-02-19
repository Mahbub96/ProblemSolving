#include <iostream>
#include <vector>
using namespace std;

using namespace std;

int findDistance(int arr[], int &s)
{
    int sum = 0;
    for (int i = 0; i < s - 1; i++)
    {
        sum += abs(arr[i] - arr[i + 1]);
    }
    return sum;
}

int main()
{
    int l;
    cin >> l;
    int arr[l], newArray[l];

    for (size_t i = 0; i < l; i++)
    {
        cin >> arr[i];
    }

    int d = findDistance(arr, l);

    /* partially sort values */
    for (int i = 0; i < l - 2; i++)
    {
        if (arr[i] > arr[i + 1] && ((abs(arr[i] - arr[i + 2])) < abs(arr[i + 1] - arr[i + 2])))
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    int d1 = findDistance(arr, l);
    cout << min(d, d1);

    return 0;
}