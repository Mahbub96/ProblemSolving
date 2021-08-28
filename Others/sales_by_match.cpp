#include <iostream>

using namespace std;

int sockMerchant(int n, int arr[])
{
    int result = 0;
    for (size_t i = 0; i < n; i++)
    {
        int temp = arr[i];
        int counter = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (temp == arr[j] && arr[j] > -1)
            {
                counter += 1;
                arr[j] = -1;
            }
        }
        result += counter / 2;
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << sockMerchant(n, arr) << endl;
    return 0;
}