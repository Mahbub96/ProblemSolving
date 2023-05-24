#include <iostream>
#include <algorithm>

using namespace std;

bool isMatch(char ch, string &str, int l)
{
    int s = 0;
    int e = l - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (str[m] == ch)
            return true;
        if (str[m] < ch)
            s = m + 1;
        if (str[m] > ch)
            e = m - 1;
    }
    return false;
}

string twoStrings(string s1, string s2)
{
    bool isFound = false;
    int l = s2.size();

    for (size_t i = 0; i < s1.size(); i++)
    {
        if (isMatch(s1[i], s2, l))
        {
            isFound = true;
            break;
        }
    }

    return isFound ? "YES" : "NO";
}

int main()
{
    string s1, s2;
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        cin >> s1 >> s2;
        sort(s2.begin(), s2.end());
        cout << twoStrings(s1, s2);
    }
}