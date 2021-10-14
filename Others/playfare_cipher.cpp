#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void tables(vector<vector<char>> &v, string key)
{
    char ch = 'A';
    int c = 0;
    int C = 0;
    char sampleTable[] = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 61, 63, 64, 91, 93, 123, 125, 33, 34, 35, 36, 37, 38, 40, 41, 44, 46};

    for (size_t i = 0; i < 9; i++)
    {

        // Push Capital Latters
        if (c <= 26)
        {
            for (size_t j = 0; j < 9; j++)
            {
                if (c == 26)
                {
                    v[i].push_back('a');
                    ch = 'b';
                    ++c;
                    break;
                }
                v[i].push_back(ch + c++);
            }
        }

        //push small Letters
        else if (c > 26 && c < 53)
        {
            for (size_t j = 0; j < 9; j++)
            {
                ++c;
                if (c <= 52)
                {
                    v[i].push_back(ch + C++);
                }
                else
                {
                    v[i].push_back(48);
                    v[i].push_back(49);
                    j += 2;
                    c += 2;
                    C = 0;
                }
            }
        }
        else
        {
            for (size_t j = 0; j < 9; j++)
            {
                v[i].push_back(sampleTable[C++]);
            }
        }

        cout << endl;
    }
}

string playFare(string plainText, string key)
{
    // Remove Duplicate
    sort(key.begin(), key.end());
    key.erase(unique(key.begin(), key.end()), key.end());

    // Generate Table
    vector<vector<char>> table(9);
    tables(table, key);

    cout << "\n\n Outputs Are : " << endl;
    for (size_t i = 0; i < table.size(); i++)
    {
        for (size_t j = 0; j < table[i].size(); j++)
        {
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }

    cout << key;
    return " ";
}

int main()
{
    playFare("str", "mahbub");
    return 0;
}