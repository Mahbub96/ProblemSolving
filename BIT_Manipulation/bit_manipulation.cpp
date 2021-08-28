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

    return 0;
}
int getOr(int a, int b)
{
    return (a & b);
}

int main()
{
    cout << getOr(7, 3) << endl;

    return 0;
}