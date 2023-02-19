#include <iostream>
#include <algorithm>

using namespace std;

void cutString(string s, int it, int len)
{
    string first_str = s.substr(0, it);
    string second_str = s.substr(it, it);

    if (first_str == second_str)
    {
        cout << "in if ,";
        s = s.substr(it, s.size());
        it = 1;
    }

    cout << it << " (it) First : " << first_str << " second : ";
    cout << second_str << " and mainString : " << s << endl;
}

int main()
{

    string s;
    cin >> s;

    int len = s.length();
    // reverse(s.begin(), s.end());
    for (size_t i = 1; i <= len / 2; i++)
    {
        cutString(s, i, len);
    }

    cout << s;

    return 0;
}