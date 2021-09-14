#include <iostream>

using namespace std;

int findPath(int i, int j, int n, int m)
{
    if (i == m || j == n) /* for cornet case */
        return 0;

    if (i == (n - 1) && j == (m - 1)) /* for last point */
        return 1;

    return findPath(i, j + 1, n, m) + findPath(i + 1, j, n, m);
}

int main()
{
    int n = 10;
    int m = 10;
    cout << findPath(0, 0, n, m);

    return 0;
}