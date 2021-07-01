#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s)
{

    /* find the length of string */
    int len = s.length();

    /* remove space using STL */
    int space = count(s.begin(), s.end(), ' ');
    remove(s.begin(), s.end(), ' ');
    s = s.substr(0, len - space);

    len = s.length();
    /* find floor and ceil of sqrt(len) */
    int row = floor(sqrt(len));
    int col = ceil(sqrt(len));

    /* check f*c >= len ?*/
    while (row * col < len)
        row++;

    /* now col and row are changing each other */
    string finalString;
    int counter = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (len - 1 >= (col * j) + i)
                finalString.push_back(s[(col * j) + i]);
            else
                break;
        }
        if (i + 1 != col)
            finalString.push_back(' ');
    }

    /* return final string */
    return finalString;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    cout << result << "\n";
    fout << result << "\n";

    fout.close();

    return 0;
}
