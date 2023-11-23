
#include <iostream>

using namespace std;

string pI = "01415926535897931159979634685441851615905761718750";

int main()
{
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        int p;
        cin >> p;
        cout << pI[p] << endl;
    }
    return 0;
}
