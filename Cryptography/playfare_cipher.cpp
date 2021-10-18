#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* A simple class for returning exact row and column */
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

/* *
 * to remove duplicated char form a string 
 * string key - received a string
 * return a string that has no repeated char 
 * this function was written by Mr Polin Khan
 * */
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

int found(string key, char ch)
{
    int len = key.length();
    for (size_t i = 0; i < len; i++)
    {
        if (ch == key[i])
            return 1;
    }
    return 0;
}

/* *
 * generate a table of n x 9 char 
 * vector<vector<char>> &v - receive a vector inside another char vector
 * string key - receive a string that will help to make proper table
 * return void 
 * */
void tables(vector<vector<char>> &v, string key)
{

    char ch = 'A';
    int c = -1;
    int C = 0;
    char val = ch + c;

    /* added special characters and numbers */
    char sampleTable[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 61, 63, 64, 91, 93, 123, 125, 33, 34, ' ', 36, 37, 38, 40, 41, 44, 46};
    int len = key.length();
    if (len > 9)
    {
        cout << "key should less then 9 word , we're making table using first 9 word of your key" << endl;
        key = key.substr(0, 9);
        len = 9;
    }

    for (size_t i = 0; i < 9; i++)
    {

        for (size_t j = 0; j < 9; j++, c++)
        {

            val = ch + c;

            /* added key infront of table */
            if (i == 0 && j == 0)
            {
                std::copy(key.begin(), key.end(), std::back_inserter(v[0]));
                j = len - 1;
            }

            /* added Upper case latter */
            else if (val >= 'A' && val <= 'Z')
            {
                if (val == 'Z')
                {
                    ch = 'a';
                    c = -1;
                }
                if (!found(key, val))
                    v[i].push_back(val);
                else
                    --j;
            }
            /* added lower case latter */
            else if (val >= 'a' && val <= 'z')
            {
                if (!found(key, val))
                    v[i].push_back(val);
                else
                    --j;
            }

            /*added number and some special Characters */
            else
            {
                val = sampleTable[C++];
                if (!found(key, val))
                    v[i].push_back(val);
                else
                    --j;
            }
        }
    }
}

/* return row and column position form generated table for a perticular pair of char */
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

/* This function will generate cipher text form plain text for a pair char*/
void convertToCipher(char &ch1, char &ch2, vector<vector<char>> &table)
{
    /*get i and j of any character from generated table */
    Trace first = findPos(table, ch1);
    Trace second = findPos(table, ch2);

    if (first.i == second.i) /* If rows are same  amd encrease column  */
    {
        ch1 = table[first.i][(first.j + 1) % 9];
        ch2 = table[second.i][(second.j + 1) % 9];
    }
    else if (first.j == second.j) /*If columns are same then encrease row */
    {
        ch1 = table[(first.i + 1) % 9][first.j];
        ch2 = table[(second.i + 1) % 9][second.j];
    }
    else /* if row and column are different */
    {
        ch1 = table[first.i][second.j];
        ch2 = table[second.i][first.j];
    }
}

/* this function will create pair of plain text and return whole cipher text */
string make_cipher(string text, vector<vector<char>> &table)
{

    size_t i = 0;
    for (; i < text.length() - 1; i += 2)
    {
        text[i] == text[i + 1] ? text.insert(i + 1, 1, ' ') : text; // for creating vocas later

        if (i < text.length() - 1)
            convertToCipher(text[i], text[i + 1], table); // H E
    }
    if (text.length() % 2)
    {
        text.push_back(' ');
        convertToCipher(text[text.length() - 2], text[text.length() - 1], table);
    }

    return text;
}

/* *
 * playFare cipher function will make a cipher text from plain text 
 * string plainText - receive a plain text that will convert into cipher text
 * string key - receive a key that will help to make hep to create a proper and secure cipher text
 * return string - return generated secure cipher text 
 * */

string playFare(string plainText, string key)
{

    if (plainText.length() == 0) // if void string occures
        plainText = " ";
    if (key.length() == 0)
        key = " ";
    /* Remove Duplicate from key */
    key = removeDuplicates(key);

    /* Generate Table */
    vector<vector<char>> table(9);
    tables(table, key);
    print(table);
    return make_cipher(plainText, table); /* to make cipher text form plaintext using play fare cipher */
}

int main()
{
    string plain_text;
    cout << "Please Enter your plain Text : ";
    getline(cin, plain_text);
    cout << "Plain text : " << plain_text << endl;

    cout << "Cipher text :" << playFare(plain_text, "apple") << endl;
    return 0;
}
