#include <iostream>

using namespace std;

int calculate(int i, int n, int a, int b)
{

    // check equality
    int temp = a;
    if (a > b)
    {
        a = b;
        b = temp;
    }

    int finalValue = 0;
    // add A
    while (n - i - 1)
    {
        finalValue += a;
        n--;
    }

    // Add B
    while (i)
    {
        finalValue += b;
        i--;
    }
    return finalValue;
}

int main()
{
    int testCase = 1;
    cin >> testCase;
    for (size_t x = 0; x < testCase; x++)
    {
        int a = 10, b = 100, n = 4;
        cin >> n >> a >> b;

        for (size_t i = 0; i < n; i++)
        {

            cout << calculate(i, n, a, b);
            if (i < n)
                cout << " ";
            if (a == b)
                break;
        }
        cout << endl;
    }
    return 0;
}