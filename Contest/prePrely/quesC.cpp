#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, req = 0, mValue = -999;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n - 1; i++)
        {
            int in, out;
            cin >> in >> out;

            req -= out;
            req += in;

            mValue = mValue < req ? req : mValue;
        }
        cout << mValue;
    }
    return 0;
}