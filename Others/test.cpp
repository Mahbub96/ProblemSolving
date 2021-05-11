#include <iostream>
#include <vector>
using namespace std;
int food = 0;
int step = 0;
int shortestPath(vector<vector<char>> &v, int right, int down, int n)
{

    if (v[right][down] == 'f')
        food++;
    if ((right + 1 < n && v[right + 1][down] != 'r'))
    {
        step++;
        cout << "Step:" << step << " R:" << right << " D:" << down << " F:" << food << endl;
        shortestPath(v, right + 1, down, n);
    }

    else if (down + 1 < n && v[right][down + 1] != 'r')
    {
        step++;
        cout << "Step:" << step << " R:" << right << " D:" << down << " F:" << food << endl;

        shortestPath(v, right, down + 1, n);
    }
    if (right == down && down == n)
        return step;
    return step;
}

void print(vector<vector<char>> v)
{
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char temp;
            cin >> temp;
            v[i].push_back(temp);
        }
    }
    print(v);
    cout << shortestPath(v, 0, 0, 3) << endl;

    return 0;
}