#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    string s;
    cin >> s;
    bool flag = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            flag = false;
            s.erase(i, 1);
            break;
        }
    }
    if (flag)
        s.erase(0, 1);
    cout << s << endl;

    return 0;
}