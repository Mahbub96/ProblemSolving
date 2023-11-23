#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */
int minimumNumber(int n, string password)
{
    int len = password.size();
    int minNum = 0;
    if ((6 - len) > 0)
        minNum = 6 - len;
    int numFound = 1;
    int LCL = 1;
    int UCL = 1;
    int SC = 1;

    for (size_t i = 0; i < len; i++)
    {
        int val = password[i];

        if (val > 47 && val < 58) /*Check numbers */
            numFound = 0;
        if (val > 96 && val < 123) /* check lower case */
            LCL = 0;
        if (val > 64 && val < 91) /*check upper case */
            UCL = 0;
        if (val > 34 && val < 44 || val == 33 || val == 45 || val == 64) /*check special charecter */
            SC = 0;

        if (!numFound && !LCL && !UCL && !SC)
            break;
    }

    minNum = max(minNum, LCL + numFound + SC + UCL);
    return minNum;
    // Return the minimum number of characters to make the password strong
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    cout << answer << endl;
    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
