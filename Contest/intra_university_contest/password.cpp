#include <iostream>

using namespace std;

int main()
{
    string s;
    while ( cin >> s ){

    string s[3];
    cin >> s[0] >> s[1] >> s[2];

    int x = 0;
    while (x < 3)
    {
        short int count = 0;

        bool digit = false;
        bool upperCase = false;
        bool lowerCase = false;

        for (int i = 0; i < s[x].size(); i++)
        {
            int val = s[x][i];

            if (val - 97 < 26 && val - 97 > -1)
            {
                lowerCase = true;
            }
            else if (val - 65 < 26 && val - 65 > -1)
            {
                upperCase = true;
            }
    }
            else if (val - 48 < 10 && val - 48 > -1)
            {
                digit = true;
            }

            else
            {
                lowerCase = false;
                upperCase = false;
                digit = false;
            }
            if (lowerCase && upperCase && digit)
            {
                ++count;
                lowerCase = false;
                upperCase = false;
                digit = false;
            }
        }
        cout << count << endl;
        x++;
    }

    return 0;
}