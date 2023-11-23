#include <iostream>
#include <vector>

using namespace std;

// For print table
void print(vector<vector<char>> v)
{
    cout << "\n\n Tables : " << endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}

string removeDuplicates(string s)
{
    int len = s.length();
    string final;
    final.push_back(s.at(0));

    for (size_t i = 1; i < len; i++)
    {
        bool found = false;
        char ch = s[i];
        for (size_t j = 0; j < final.length(); j++)
        {
            if (ch == final[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
            final.push_back(ch);
    }

    return final;
}

void tables(vector<vector<char>> &v, string key)
{
    char ch = 'A';
    int c = 0;
    int C = 0;
    /* added special characters and numbers */
    char sampleTable[] = {50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 61, 63, 64, 91, 93, 123, 125, 33, 34, 35, 36, 37, 38, 40, 41, 44, 46};

    for (size_t i = 0; i < 9; i++)
    {

        // Push Capital Latters
        if (c <= 26)
        {
            for (size_t j = 0; j < 9; j++)
            {
                // when all capital laters has been pushed
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

        // push all special characters and numbers
        else
        {
            for (size_t j = 0; j < 9; j++)
            {
                v[i].push_back(sampleTable[C++]);
            }
        }
    }
}

string playFare(string plainText, string key)
{
    // Remove Duplicate
    key = removeDuplicates(key);

    // Generate Table
    vector<vector<char>> table(9);
    tables(table, key);
    print(table);
    return " ";
}

int main()
{
    cout << playFare("mahbub", "aabccb") << endl;
    return 0;
}
