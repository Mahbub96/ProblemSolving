#include <iostream>

using namespace std;

int main()
{
    long long n, q;

    cin >> n >> q;

    long long arr[999999];

    for (long long i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[temp] = temp;
    }
    long long a, b, x;
    for (long long i = 0; i < q; i++)
    {
        cin >> a >> b >> x;

        if (arr[x] == x)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}