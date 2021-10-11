#include <iostream>
using namespace std;

bool getBitN(int n, int i)
{
    return (n & (i << 1));
}

int setBitN(int n, int i)
{
    return (n | (i << 1));
}
int updateBitN(int n, int i, int k)
{
    /* Incomplete */
}
int getOr(int a, int b)
{
    return (a & b);
}

int main()
{
    cout << getBitN(10, 0) << endl;
    cout << getBitN(10, 1) << endl;
    cout << getBitN(10, 2) << endl;
    cout << getBitN(10, 3) << endl;

    return 0;
}