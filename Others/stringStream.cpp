#include <iostream>
#include <vector>
using namespace std;

vector<int> parseInts(string str)
{

    vector<int> v;
    for (size_t i = 0, j = 0; i <= str.size(); i++)
    {
        if (str[i] != ',' && i != str.size())
            continue;
        v.push_back(stoi(str.substr(j, i - j)));
        j = i + 1;
    }
    return v;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);

    for (int i = 0; i < integers.size(); i++)
        cout << integers[i] << "\n";

    return 0;
}
