#include <iostream>
#include <map>

using namespace std;

int main()
{

    int n;
    cin >> n;
    multimap<string, string> database;

    for (int i = 0; i < n; i++)
    {
        string name, mail;
        cin >> name >> mail;
        database.insert(pair<string, string>(name, mail));
    }

    multimap<string, string>::iterator mit = database.begin();

    for (mit = database.begin(); mit != database.end(); mit++)
    {
        if (mit->second.find("@gmail.com") != string::npos)
        {
            cout << mit->first << endl;
        }
    }

    return 0;
}