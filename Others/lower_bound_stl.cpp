#include <bits/stdc++.h>

using namespace std;

int main()
{
    int len;
    cin >> len;
    vector<int> v;
    for (int i = 0; i < len; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    cin >> len;
    for (size_t i = 0; i < len; i++)
    {
        int temp;
        cin >> temp;
        if (binary_search(v.begin(), v.end(), temp))
            cout << "Yes " << (lower_bound(v.begin(), v.end(), temp) - v.begin()) + 1 << endl;
        else
            cout << "No " << (lower_bound(v.begin(), v.end(), temp) - v.begin()) + 1 << endl;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
