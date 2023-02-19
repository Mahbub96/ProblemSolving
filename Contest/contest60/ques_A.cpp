#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string s;
        cin >> s;
        vector<char> v(s.begin(), s.end());

        int l = s.size();
        int b = 0;

        for (int j = 0; j < l; j++)
        {
            if (s.at(j) == '(')
                ++b;
            else if (s.at(j) == ')')
                --b;
        }

        if (b)
        {
            cout << "Case " << i + 1 << ": impossible" << endl;
        }
        else
        {

            int step = 0;
            int temp = 0;
            for (int j = 0; j < l; j++)
            {

                if (v[j] == '(')
                {
                    ++temp;
                }
                else if (v[j] == ')')
                {
                    --temp;
                }

                if (temp < 0)
                {
                    vector<char>::iterator it = v.begin();
                    ++step;
                    v.erase(it + j);
                    v.push_back(')');
                    j--;
                    ++temp;
                }
            }
            cout << "Case " << i + 1 << ": " << step << endl;
        }
    }

    return 0;
}