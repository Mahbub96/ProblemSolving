#include <iostream>
#include <vector>

using namespace std;

class Trace
{
public:
    int i, j;
};

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

// int fina_duplicate(char ch, string *s)
// {
//     int len = s->length();

//     for (size_t i = 0; i < len; i++)
//     {
//         if (ch == s->at(i))
//         {
//             return i;
//         }
//     }
//     return -1;
// }

/* Taken form polin to remove diplicate values */
string removeDuplicates(string key)
{
    bool isVisit[130] = {0};
    string final;
    int len = key.length();
    for (int i = 0; i < len; i++)
    {
        if (!isVisit[(int)key.at(i)])
        {
            final.push_back(key.at(i));
            isVisit[(int)key.at(i)] = 1;
        }
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

Trace findPos(vector<vector<char>> &table, char &ch)
{
    Trace t;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (ch == table[i][j])
            {
                t.i = i;
                t.j = j;
                return t;
            }
        }
    }
    return t;
}

void convertToCipher(char &ch1, char &ch2, vector<vector<char>> &table)
{

    Trace first = findPos(table, ch1);

    Trace second = findPos(table, ch2);

    if (first.i == second.i)
    {
        ch1 = table[first.i][(first.j + 1) % 9];
        ch2 = table[second.i][(second.j + 1) % 9];

    } /*column encrease */
    else if (first.j == second.j)
    { /*row encrease */
        ch1 = table[(first.i + 1) % 9][first.j];
        ch2 = table[(second.i + 1) % 9][second.j];
    }
    else
    {
        ch1 = table[first.i][second.j];
        ch2 = table[second.i][first.j];
    }
}

// to make cipher from plaintext
string make_cipher(string text, vector<vector<char>> &table)
{

    // int len = text.length();
    size_t i = 0;
    for (; i < text.length() - 1; i += 2)
    {
        text[i] == text[i + 1] ? text.insert(i + 1, 1, '#') : text; // for creating vocas later

        if (i < text.length() - 1)
            convertToCipher(text[i], text[i + 1], table); // H E
    }
    if (text.length() % 2)
    {
        text.push_back('#');
        convertToCipher(text[text.length() - 2], text[text.length() - 1], table);
    }

    return text;
}

string playFare(string plainText, string key)
{
    string cipher;
    // Remove Duplicate
    key = removeDuplicates(key);
    if (plainText.length() == 0) // if void string occures
        plainText = " ";

    // Generate Table
    vector<vector<char>> table(9);
    tables(table, key);
    print(table);
    string cipher_text = make_cipher(plainText, table);
    cout << cipher_text << endl;
    return " ";
}

int main()
{
    cout << playFare("helloo", "mahbub") << endl;
    return 0;
}
