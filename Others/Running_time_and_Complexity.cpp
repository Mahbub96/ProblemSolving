#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool isPrime(long int &n)
{
    if (n == 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (!(n % i))
            return false;
    }
    return true;
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    while (n--)
    {
        long int value;
        cin >> value;
        bool flag = isPrime(value);

        if (flag)
        {
            cout << "Prime" << endl;
        }
        else
            cout << "Not prime" << endl;
    }
    return 0;
}
