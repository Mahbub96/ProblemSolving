#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check the small string
bool compare(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

string has_substring(vector<string> &s)
{
    int len = s.size();

    for (int i = 0; i < len - 1; i++)
    {
        string sub = s[i];

        for (int j = i + 1; j < len; j++)
        {
            short int l = sub.size();
            string sup1 = s[j].substr(0, l);

            if (sup1 == sub)
            {
                return "NO";
            }
        }
    }
    return "YES";
}

int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (n--)
    {
        int m;
        cin >> m;
        vector<string> arr;
        while (m--)
        {
            string s;
            cin >> s;
            arr.push_back(s);
        }

        sort(arr.begin(), arr.end(), compare);

        cout << "Case " << i++ << ": " << has_substring(arr) << endl;
    }

    return 0;
}