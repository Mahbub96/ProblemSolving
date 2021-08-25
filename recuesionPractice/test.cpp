#include <iostream>
using namespace std;

int main()
{
    int x;
    while (1)
    {
        try
        {
            cin >> x;
            if (!cin)
            {
                throw "exception";
            }
            cout << x;
        }
        catch (...)
        {
            cout << "Enter integer";
        }
    }
}