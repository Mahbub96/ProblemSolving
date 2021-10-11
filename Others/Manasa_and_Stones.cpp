//Incomplete Code 
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

string binaryCombination;
int lengths(int N)
{

    // To store the binary number
    long int B_Number = 0;
    int cnt = 0;
    while (N != 0)
    {
        int rem = N % 2;
        long int c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;

        // Count used to store exponent value
        cnt++;
    }

    return B_Number;
}

string decToBinary(int n, int s)
{
    // Size of an integer is assumed to be 32 bits
    string str;
    for (int i = s; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
        {

            str.append("1");
        }
        // cout << "1";
        else
        {

            str.append("0");
        }
    }
    return str;
}

int main()
{
    int test;
    cin >> test;
    for (size_t i = 0; i < test; i++)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int s = to_string(lengths(n)).size();
        // vector<vector<string>> v(s);
        cout << s << endl;
        for (size_t i = 0; i < s; i++)
        {
            cout << decToBinary(i, s) << endl;
        }
    }

    return 0;
}
