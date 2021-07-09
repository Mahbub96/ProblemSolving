#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p)
{
    return min(p / 2, (n - p) / 2);
}

int main()
{
    int n, p;
    cin >> n >> p;

    int result = pageCount(n, p);

    cout << result << "\n";

    return 0;
}
