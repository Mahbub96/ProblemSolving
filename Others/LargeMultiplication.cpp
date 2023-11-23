/* Large Multiplication */

#include <iostream>
#include <deque>

using namespace std;

// Big Multiplication as like Human
string multiplication(int num1, int num2)
{
    string a = to_string(num1);
    string b = to_string(num2);

    string s;
    return s;
}

/**
 * @brief Its a big Multiplication calculated program
 * 
 * @param a string
 * @param b string
 * @return string 
 */
string multiplication(string a, string b)
{

    bool isFirstDone = false;
    int aLen = a.length();
    int bLen = b.length();

    deque<string> firstLine, secondLine, result;

    for (short int i = 0; i < aLen; i++)
    {
        short int sum = 0;
        short int carry = 0;

        for (int j = 0; j < bLen; j++)
        {

            short int firstNum = b[bLen - 1 - j] - 48;
            short int secondNum = a[aLen - 1 - i] - 48;

            if (!isFirstDone)
            {
                short int res = firstNum * secondNum;
                if (carry)
                {
                    res += carry;
                }
                if (res > 9)
                {
                    sum = res % 10;
                    carry = res / 10;
                }
                else
                {
                    carry = 0;
                    sum = res;
                }
                if (j + 1 != bLen)
                {
                    firstLine.push_front(to_string(sum));
                }
                else
                {
                    firstLine.push_front(to_string(sum));
                    firstLine.push_front(to_string(carry));
                }
            }

            else
            {
                short int res = firstNum * secondNum;
                if (carry)
                {
                    res += carry;
                }
                if (res > 9)
                {
                    sum = res % 10;
                    res /= 10;
                    carry = res;
                }
                else
                {
                    carry = 0;
                    sum = res;
                }
                if (j + 1 != bLen)
                {
                    secondLine.push_front(to_string(sum));
                }
                else
                {
                    secondLine.push_front(to_string(sum));
                    secondLine.push_front(to_string(carry));
                }
            }
        }

        if (!isFirstDone)
            secondLine.push_front("0");
        isFirstDone = true;
    }
    if (firstLine.size() > secondLine.size())
    {
        while (firstLine.size() != secondLine.size())
        {
            secondLine.push_front("0");
        }
    }
    else
    {
        while (firstLine.size() != secondLine.size())
        {
            firstLine.push_front("0");
        }
    }

    string res;
    short int sum = 0;
    bool carry = false;
    int len = firstLine.size();
    deque<string> rslt;

    // cout << stoi(firstLine.at(2));
    for (short int i = 0; i < len; i++)
    {
        int firstNum = stoi(firstLine.at(len - 1 - i));
        int secondNum = stoi(secondLine.at(len - 1 - i));
        int r = firstNum + secondNum;
        // cout << firstNum << " " << secondNum << " " << r << endl;
        if (carry)
        {
            ++r;
        }
        if (r > 9)
        {
            sum = r % 10;
            carry = true;
        }
        else
        {
            sum = r;
            carry = false;
        }

        rslt.push_front(to_string(sum));
    }

    for (short int i = 0; i < rslt.size(); i++)
    {
        res.append(rslt[i]);
    }

    return res[0] == '0' ? res.substr(1, res.length()) : res;
}

int main()
{
    cout << multiplication("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

    return 0;
}