<<<<<<< HEAD
/******* 
 * No Idea
 * Anti Brain 
 * Idot 
 * trying to generate an idea 
 * pray for me 
 *******/
=======
#include <iostream>
#include <deque>

using namespace std;

class Graph
{
public:
    int value;
    deque<Graph *> neighbor;

    Graph(int value)
    {
        this->value = value;
    }

    void DFS()
    {
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
    findNode(g, a)->neighbor.push_back(findNode(g, b));
    findNode(g, b)->neighbor.push_back(findNode(g, a));
}

int main()
{

    deque<Graph *> g;

    crateNode(g, 10);
    crateNode(g, 7);

    connect(g, 10, 7);

    cout << g[0]->neighbor[0]->value << endl;
    cout << g[1]->neighbor[0]->value << endl;

    return 0;
}
>>>>>>> dev
