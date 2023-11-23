#include <iostream>

using namespace std;

int main()
{
    double n, m;
    cin >> n >> m;

    long long arr[1000000];

    for (long long i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        arr[temp] = i;
    }

    for (long long i = 0; i < m; i++)
    {
        long long a, b, x;
        cin >> a >> b >> x;

        if (arr[x] && arr[x] >= a && arr[x] <= b)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}