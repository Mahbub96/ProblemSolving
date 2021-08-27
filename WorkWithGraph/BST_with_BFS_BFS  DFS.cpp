#include <iostream>
#include <queue>

using namespace std;

/* Pure Binary tree */

class Node
{
    int value, level;
    Node *left;
    Node *right;

public:
    Node(int val, int l)
    {
        value = val;
        level = l;
        left = NULL;
        right = NULL;
    }

    /** Start Input Sector **/
    void append(int val)
    {
        Node *last = findAppropiatePosition(this, val);

        if (val <= last->value)
            appendLeft(last, val);
        else
            appendRight(last, val);
    }

    /** 
     * DFS function for check DFS of this Fucntion 
     */
    void DFS()
    {
        int value;
        cout << "Enter a node , where you want to start DFS : ";
        cin >> value;
        Node *root = getTargetNode(value);
        if (root)
            child(root);
        else
            cout << "Node is Empty!" << endl
                 << endl;
    }

    /*** start BFS ***/
    void BFS()
    {
        int startNode;
        cout << "Enter Start Node : ";
        cin >> startNode;

        Node *targetRootNode = getTargetNode(startNode);
        queue<Node *> q, trace;

        q.push(targetRootNode);
        trace.push(targetRootNode);
        int prevLevel = q.front()->level;
        while (q.size())
        {
            int value = q.front()->value;
            int level = q.front()->level;

            if (q.front()->left)
            {
                q.push(q.front()->left);
                trace.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
                trace.push(q.front()->right);
            }

            /** If new Level start , Prev level's Value will pop **/
            if (prevLevel != level)
            {
                int l = trace.front()->level;
                while (trace.size() && (trace.front()->level == l))
                {
                    cout << trace.front()->value << " ";
                    trace.pop();
                }
                cout << endl;
                prevLevel = level;
            }
            q.pop();
        }
        /** Print last level's Leaf node only **/
        while (trace.size())
        {
            cout << trace.front()->value << " ";
            trace.pop();
        }
    }

private:
    /*add value at leaf node */
    void appendLeft(Node *leaf, int value) { leaf->left = new Node(value, leaf->level + 1); }
    void appendRight(Node *leaf, int value) { leaf->right = new Node(value, leaf->level + 1); }
    Node *findAppropiatePosition(Node *n, int &val)
    {
        bool isContinue = true;
        while (isContinue)
        {

            if (val <= n->value)
            {

                if (n->left)
                    n = n->left;
                else
                    isContinue = false;
            }
            else
            {

                if (n->right)
                    n = n->right;
                else
                    isContinue = false;
            }
        }
        return n;
    }
    /** End Input Sector **/

    /** Start DFS Sector **/
    void child(Node *n)
    {
        cout << "Node : " << n->value << " -> Level : " << n->level << endl;
        if (n->left)
            child(n->left);

        if (n->right)
            child(n->right);
    }

    /** End DFS sector **/
    /** Start code for BFS **/
    Node *getTargetNode(int value)
    {
        Node *n = this;
        bool isContinue = true;

        if (n->value == value)
            return n;

        while (isContinue)
        {

            if (value <= n->value)
            {

                if (n->left)
                {
                    n = n->left;
                    if (n->value == value)
                        return n;
                }
                else
                    isContinue = false;
            }
            else
            {

                if (n->right)
                {
                    n = n->right;
                    if (n->value == value)
                        return n;
                }
                else
                    isContinue = false;
            }
        }
        return n;
    }
};

/** this is a helfer function of append**/
Node *addNode(Node *tree)
{

    int val;
    cout << "please Enter new value to Add : ";
    cin >> val;

    if (!tree)
    {
        tree = new Node(val, 0);
        cout << val << " Added as Root node \n\n"
             << endl;
        return tree;
    }

    tree->append(val);
    return tree;
}

int main()
{
    Node *root;
    while (true)
    {
        cout << "\n\n\t\t[Admin Panal of Node Example Console]\n\t1.Add New Node.\t\t2.DFS\n\t3.BFS\t\t\t4.Exit \n\nEnter your choice : ";
        int choice;

        cin >> choice;

        switch (choice)
        {
        case 1:

            root = addNode(root);

            break;

        case 2:
            root->DFS();
            break;
        case 3:
            root->BFS();
            break;

        default:
            break;
        }
    }

    return 0;
}