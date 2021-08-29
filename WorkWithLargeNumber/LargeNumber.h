#include <algorithm>
#include <cmath>
using namespace std;

string largeAdd(string a, string b)
{
    int aLen = a.size();
    int bLen = b.size();
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

string largeMinus(string a, string b)
{
    string result;
    int aLen = a.size();
    int bLen = b.size();
    bool carry = false;

    if ((aLen < bLen) || (aLen == bLen && (a.at(0) - 48) < (b.at(0) - 48)))
    {
        return "First Number Should be Larger then Second ";
    }

    while (a.size() > 0)
    {
        aLen = a.size();
        bLen = b.size();
        short unsigned int firstNumber = a.at(aLen - 1) - 48;
        short unsigned int secondNumber = 0;

        if (bLen > 0)
        {
            secondNumber = b.at(bLen - 1) - 48;
        }
        else
        {
            secondNumber = 0;
        }
        if (carry)
        {
            secondNumber++;
            carry = false;
        }

        /*** if upper number is less then down number or not **/
        short unsigned int res;
        if (firstNumber < secondNumber)
        {
            firstNumber += 10;
            carry = true;
        }
        res = firstNumber - secondNumber;

        a.pop_back();

        if (bLen > 0)
            b.pop_back();
        if (a.length() == 0 && res == 0)
            continue;
        result.append(to_string(res));
    }
    if (carry)
        cout << "why carry ?" << endl;
    reverse(result.begin(), result.end());
    return result;
}

/**
 * @brief Its a big Multiplication calculated program
 * 
 * @param a string
 * @param b string
 * @return string 
 */
string largeMultiplication(string firstInp, string secondInp)
{
    string firstLine, secondLine;
    int sizeA = firstInp.size();
    int sizeB = secondInp.size();

    string largeNumber, smallNumber;
    if (sizeA >= sizeB)
    {
        largeNumber = firstInp;
        smallNumber = secondInp;
    }
    else
    {
        largeNumber = secondInp;
        smallNumber = firstInp;
    }
    int small = smallNumber.size();
    int large = largeNumber.size();

    string line[small];
    for (int i = 0; i < small; i++)
    {
        unsigned short int carry = 0;
        unsigned short int base = smallNumber.at(small - i - 1) - 48;
        int k = i;
        while (k--)
            line[i].append("0");
        for (int j = 0; j < large; j++)
        {

            unsigned short int num = largeNumber.at(large - j - 1) - 48;
            unsigned short int mul = num * base;

            /* Incomplete part for carry */
            if (carry)
            {
                mul += carry;
                carry = 0;
            }
            if (mul > 9)
            {
                carry = mul / 10;
                mul %= 10;
            }

            // cout << "base:" << base << " num:" << num << " mul:" << mul << " carry:" << carry << endl;
            line[i].append(to_string(mul));
        }
        if (carry)
            line[i].append(to_string(carry));

        reverse(line[i].begin(), line[i].end());
    }

    /* for Add two number */
    string result = "0";
    for (int i = 0; i < small; i++)
    {
        result = largeAdd(line[i], result);
    }

    return result;
}
// Big Multiplication as like Human
string largeMultiplication(long int num1, long int num2)
{
    string a = to_string(num1);
    string b = to_string(num2);

    return largeMultiplication(a, b);
}