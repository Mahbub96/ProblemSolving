#include <iostream>
#include <map>
using namespace std;

int main()
{

    map<int, int> m;
    map<int, int>::iterator i;

    // m.insert(pair<int, int>(1, 2));
    // m.insert(pair<int, int>(2, 2));
    // m.insert(pair<int, int>(3, 2));
    // m.insert(pair<int, int>(4, 2));
    m[0] = 2;
    m[1] = 2;
    m[2] = 2;
    m[3] = 2;
    m[4] = 2;

    for (i = m.begin(); i != m.end(); i++)
    {
        /* code */
        cout << "Key : " << i->first << " Value : " << i->second << endl;
    }

    return 0;
}