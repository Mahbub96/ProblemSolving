#include <iostream>
#include <string>

using namespace std;

void replacePI(string s)
{
    if (!s.length())
        return;

    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacePI(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacePI(s.substr(1));
    }
}

int main()
{
    replacePI("piiiiiipii");
    return 0;
}