#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> &v)
{

    int startingNode;
    cout << "Enter Starting Node for start BFS : ";
    cin >> startingNode;

    queue<int> q, output;
    int currentNodeSize = 0;
    q.push(startingNode);

    while (q.size())
    {
        int currentNode = q.front();

        int parents = v[currentNode].size();

        for (size_t i = 0; i < v[currentNode].size(); i++)
        {
            q.push(v[currentNode][i]);
            output.push(v[currentNode][i]);
        }

        cout << currentNode << " ";
        q.pop();
    }
}

void input(vector<vector<int>> &v)
{

    for (size_t i = 0; i < v.size(); i++)
    {
        int child;
        cout << "\nHow many child for node" << i << " : ";
        cin >> child;
        for (size_t j = 0; j < child; j++)
        {
            cout << "Enter " << j << "no child for node " << i << " : ";
            int temp;
            cin >> temp;
            v[i].push_back(temp);
        }
    }
}

int main()
{
    int totalNode;
    cout << "Enter total Node : ";
    cin >> totalNode;

    /* input sector */
    vector<vector<int>> v(totalNode);
    input(v);

    BFS(v);

    return 0;
}