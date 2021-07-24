#include <algorithm>
#include <cmath>
using namespace std;

string largeAdd(string a, string b)
{
    int aLen = a.length();
    int bLen = b.length();
    string result;
    bool carry = false;

    int large = max(aLen, bLen);
    int small = min(aLen, bLen);

    for (int i = 0; i < large; i++)
    {
        short unsigned int firstNumber = 0;
        short unsigned int secondNumber = 0;

        if (aLen >= bLen)
        {
            firstNumber = a.at(aLen - i - 1) - 48;
            if (carry)
                ++firstNumber;
            if (i < small)
            {
                secondNumber = b.at(bLen - i - 1) - 48;
            }
            else
            {
                secondNumber = 0;
            }
        }
        else
        {
            firstNumber = b.at(bLen - i - 1) - 48;
            if (carry)
                ++firstNumber;
            if (i < small)
            {
                secondNumber = a.at(aLen - i - 1) - 48;
            }
            else
            {
                secondNumber = 0;
            }
        }
        int res = firstNumber + secondNumber;
        if (res > 9)
        {
            res %= 10;
            carry = true;
        }
        else
        {
            carry = false;
        }
        result.append(to_string(res));
    }
    if (carry)
        result.append("1");
    reverse(result.begin(), result.end());
    return result;
}