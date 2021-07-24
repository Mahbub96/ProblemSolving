/* Large Multiplication */
#include <iostream>
#include "LargeNumber.h"

using namespace std;

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
int main()
{
    cout << largeMultiplication(12, 3);

    return 0;
}