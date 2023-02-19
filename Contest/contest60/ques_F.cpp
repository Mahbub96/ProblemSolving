#include <iostream>

using namespace std;

int main()
{
    int pi[] = {1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3};
    int t, x;
    cin >> t;
    while (t--)
    {
        int sum = 0;
        cin >> x;
        if (x < 16)
        {
            for (int i = 0; i < x; i++)
            {
                sum += pi[i];
            }
            cout << sum << endl;
        }
    }
    return 0;
}