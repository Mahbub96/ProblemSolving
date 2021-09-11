#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    int count = 0;
    string standard = "SOS";
    for (size_t i = 0; i < s.size();)
    {
        for (size_t j = 0; j < 3; ++j, ++i)
        {
            if (s[i] == standard[j])
                continue;
            count++;
        }
    }

    return count;
}

int main()
{
    string s = "PoB";
    cout << marsExploration(s);
    return 0;
}