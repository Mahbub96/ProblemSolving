#include <iostream>
#include <deque>

using namespace std;

class Graph
{
public:
    int value;
    deque<Graph *> neighbour;

    Graph(int value)
    {
        this->value = value;
    }

    void DFS()
    {
        cout << this->value << endl;
    }
};

/*** Global Functions like public static function ***/
void crateNode(deque<Graph *> &g, int value)
{
    Graph *node = new Graph(value);
    g.push_back(node);
}

Graph *findNode(deque<Graph *> g, int value)
{
    int i;
    for (i = 0; i < g.size(); i++)
    {
        if (value == g[i]->value)
            break;
    }
    return g[i];
}
/** for connecting two nodes **/
void connect(deque<Graph *> &g, int a, int b)
{
    findNode(g, a)->neighbour.push_back(findNode(g, b));
    findNode(g, b)->neighbour.push_back(findNode(g, a));
}
void show(deque<Graph *> &g)
{
    deque<Graph *> temp = g;
    for (size_t i = 0; i < temp.size(); i++)
    {
        cout << "\n\nNode : " << temp[i]->value << endl;
        for (size_t j = 0; j < temp[i]->neighbour.size(); j++)
        {
            cout << "\tneighbour : " << temp[i]->neighbour[j]->value << endl;
        }
    }
}
int main()
{

    deque<Graph *> g;

    crateNode(g, 0);
    crateNode(g, 1);
    crateNode(g, 2);
    crateNode(g, 3);
    crateNode(g, 4);
    /*** work with node 0 **/
    connect(g, 0, 1);
    connect(g, 0, 4);
    /*** work with node 1 **/
    connect(g, 1, 4);
    connect(g, 1, 3);
    /*** work with node 2 **/
    connect(g, 2, 1);
    /*** work with node 3 **/
    connect(g, 3, 2);
    connect(g, 3, 4);

    show(g);

    return 0;
}