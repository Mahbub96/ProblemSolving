#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int k = 0, prev = 0, extra_k = 0;
        int n;
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            int temp = val - prev;
            if (temp == k)
            {
                k++;
            }
            k = max(k, temp);
            prev = val;
        }

        cout << "Case " << i << ": " << k << endl;
    }

    return 0;
}