/* Large Multiplication */
#include <iostream>
#include "LargeNumber.h"

using namespace std;

string factorial(string n)
{
    if (n.size() == 1 && n[0] == '1')
        return "1";
    return largeMultiplication(n, factorial(largeMinus(n, "1")));
}

int main()
{

    // cout << largeMultiplication("20", "10") << endl;
    string s;
    cout << "Enter a number that you want to make show factorial : ";
    cin >> s;
    cout << factorial(s) << endl
         << endl;
    // cout << largeAdd("10", "31") << endl;
    // cout << largeMinus("109", "49") << endl;

    return 0;
}
