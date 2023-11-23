//Problem of day 29

#include <iostream>

using namespace std;

/*
 * Complete the 'bitwiseAnd' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER K
 */

int bitwiseAnd(int n, int k)
{

    int value = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            /* code */
            int temp = i & j;
            if (temp > value && temp < k)
            {
                value = temp;
            }
        }
    }
    return value;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        cout << bitwiseAnd(n, k) << endl;
    }

    return 0;
}
