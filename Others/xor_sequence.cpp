#include <iostream>
using namespace std;

int sequenceMaker(int l, int r)
{
    int res;
    int count = 0;
    while (l % 4 != 0)
    {
        l--;
        count++;
    }

    switch (count)
    {
    case 0:
        res = l;
        break;
    case 1:
        res = 1;
        break;
    case 2:
        res = l + 3;
        break;
    case 3:
        res = 0;
        break;
    }

    for (int i = l + count + 1; i <= r; i++)
    {
        if (i % 4 == 0)
        {
            res = res ^ i;
        }
        else if (i % 4 == 1)
        {
            res = res ^ 1;
        }
        else if (i % 4 == 2)
        {
            res = res ^ (i + 1);
        }
        else if (i % 4 == 3)
        {
            res = res ^ 0;
        }
    }
    return res;
};

int nth_xor_value(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return (1 ^ 0);

    return nth_xor_value(n % 3);
}

int main()
{
    int x = 0;
    int l = 15; // 1111
    int r = 20; // 10100
    for (int i = 0; i < 14; i++)
    {

        x = x ^ nth_xor_value(i);
        cout << x << endl;
    }
    cout << x << endl;
    // cout << sequenceMaker(l, r) << endl;

    return 0;
}