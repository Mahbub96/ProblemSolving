#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int times;
    set<int> s;
    cin >> times;
    for (size_t i = 0; i < times; i++)
    {
        int check, x;
        cin >> check >> x;
        if (check == 1)
            s.insert(x);

        else if (check == 2)
            s.erase(x);
        else if (check == 3)
        {
            /* find value*/
            set<int>::iterator itr = s.find(x);
            if (itr == s.end())
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}