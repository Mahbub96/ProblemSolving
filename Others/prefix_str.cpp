#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool has_substring(vector<string> s)
{
    bool isFound = false;
    for (int i = 0; i < s.size(); i++)
    {
        string sub = s[i];

        for (int j = i + 1; j < s[i].size(); j++)
        {
            int l = sub.size();
            string sup = s[j];
            string sup1 = sup.substr(0, l);

            if (sup1 == sub)
            {
                isFound = true;
                break;
            }
            if (isFound)
                break;
        }
        if (isFound)
            break;
    }
    return isFound;
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
        sort(arr.begin(), arr.end());
        string res = has_substring(arr) ? "YES" : "NO";
        cout << "Case " << i++ << ": " << res << endl;
    }

    return 0;
}