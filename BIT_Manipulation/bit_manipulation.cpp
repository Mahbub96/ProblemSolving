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

int main()
{
    // cout << getBitN(4, 2);
    // cout << setBitN(3, 2) << endl;
    return 0;
}