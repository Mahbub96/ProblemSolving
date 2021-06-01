#include <iostream>
#include <string>
using namespace std;

void reverseString(string s)
{
    if (!s.length())
    {
        return;
    }
    reverseString(s.substr(1));
    cout << s.front();
}

int main()
{

    reverseString("abcde");

    return 0;
}