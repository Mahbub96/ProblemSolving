#include <bits/stdc++.h>

using namespace std;

// strings at index 0 is not used, it is to make array
// indexing simple
string one[] = {"", "one ", "two ", "three ", "four ",
                "five ", "six ", "seven ", "eight ",
                "nine ", "ten ", "eleven ", "twelve ",
                "thirteen ", "fourteen ", "fifteen ",
                "sixteen ", "seventeen ", "eighteen ",
                "nineteen "};

// strings at index 0 and 1 are not used, they is to
// make array indexing simple
string ten[] = {"", "", "twenty ", "thirty ", "forty ",
                "fifty ", "sixty ", "seventy ", "eighty ",
                "ninety "};

string number_to_word(int n)
{
    string final;
    if (n > 19)
        final = ten[n / 10] + one[n % 10];
    else
        final = one[n];

    return final;
}

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m)
{
    string finalOutput;
    string hour;
    string minute;

    if (m == 15 || m == 30 || m == 45)
    {

        if (m == 15)
        {
            finalOutput = "quarter past " + number_to_word(h);
            return finalOutput;
        }
        else if (m == 30)
        {
            finalOutput = "half past " + number_to_word(h);
            return finalOutput;
        }
        else
        {
            if (h == 12)
                finalOutput = "quarter to " + number_to_word(1);

            else
                finalOutput = "quarter to " + number_to_word(h + 1);
            return finalOutput;
        }
    }

    if (m == 0)
    {
        string hour = number_to_word(h);
        finalOutput = hour + "o' clock";
    }
    /*before 31 min*/
    else if (1 <= m && m <= 30)
    {
        hour = number_to_word(h);
        minute = number_to_word(m);

        if (m == 1)
            finalOutput = minute + "minute past " + hour;
        
        else
           finalOutput = minute + "minutes past " + hour;
        
    }

    /*after 30 min*/
    else
    {
        minute = number_to_word(60 - m);
        hour = number_to_word(h + 1);

        finalOutput = minute + "minutes to " + hour;
    }

    return finalOutput;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

    fout << result << "\n";

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
