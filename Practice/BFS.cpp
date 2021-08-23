#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define visited 1
#define notVisited 0
int visit[100];

int main()
{
    int node;
    cin >> node;
    vector<int> v[node];

    for (size_t i = 0; i < node; i++)
    {
        int edge;
        cin >> edge;
        for (size_t j = 0; j < edge; j++)
        {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    /* visited nonVisited and visit[100] are global array
    visited = 1,nonVisited = 0
    */
    queue<int> q;
    int x, s;
    cout << "\nEnter BFS starting node : ";
    cin >> s;
    q.push(s);
    visit[s] = visited;
    cout << "\nVisited node : ";
    while (q.size())
    {
        x = q.front();
        cout << " " << x;
        q.pop();
        for (int i = 0; i < v[x].size(); i++)
        {
            if (visit[v[x][i]] == notVisited)
            {
                q.push(v[x][i]);
                visit[v[x][i]] = visited;
            }
        }
    }

    return 0;
}