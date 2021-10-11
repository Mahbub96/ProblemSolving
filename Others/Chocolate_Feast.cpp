#include <iostream>

using namespace std;

/*
 * Complete the 'chocolateFeast' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c
 *  3. INTEGER m
 */
int chocolateFeast(int n, int c, int m)
{
    int totalChocolate = n / c;
    int khosha = totalChocolate;

    while (khosha >= m)
    {
        khosha -= m;
        khosha++;
        totalChocolate++;
    }
    return totalChocolate;
}

int main()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int n, c, m;
        cin >> n >> c >> m;
        cout << chocolateFeast(n, c, m) << endl;
    }

    return 0;
}