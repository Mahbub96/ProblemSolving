#include <iostream>

using namespace std;

long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

long long lcm(long long int a, long long int b)
{
    return (a / gcd(a, b) * b);
}

int main()
{

    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        long long int a, b;
        cin >> a >> b;
        string res = (a + b) == (gcd(a, b) + lcm(a, b)) ? "true" : "false";
        cout << res << endl;
    }
}