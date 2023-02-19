#include <iostream>

using namespace std;

int main()
{
    int arr[3], maxIndex = 0, res = 0, m = -9999;
    int arr2[4];

    cin >> arr[0] >> arr[1] >> arr[2];

    m = max(arr[0] + arr[1] * arr[2], m);
    m = max((arr[0] * (arr[1] + arr[2])), m);
    m = max(arr[0] * arr[1] * arr[2], m);
    m = max((arr[0] + arr[1]) * arr[2], m);

    cout << m;

    return 0;
}