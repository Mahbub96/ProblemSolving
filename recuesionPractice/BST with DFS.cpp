#include <iostream>
#include <queue>

using namespace std;

/* Pure Binary tree */

class Node
{
    int value;
    Node *left;
    Node *right;

    /** Start Input Sector **/

    /* find leaf node to add new value */

public:
    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
    void append(int val)
    {
        Node *last = findAppropiatePosition(this, val);
        if (val <= last->value)
            appendLeft(last, val);
        else
            appendRight(last, val);
    }
    void DFS()
    {
        if (this)
            child(this);
        else
            cout << "Node is Empty!" << endl
                 << endl;
    }

    /*** start BFS ***/
    void BFS()
    {
        queue<Node *> q;
        int startNode;
        cout << "Enter Start Node : ";
        cin >> startNode;

        Node *targetRootNode = getTargetNode(startNode);
        cout << "target Node : " << targetRootNode->value << endl;
        q.push(targetRootNode);
        while (q.size())
        {
            int val = q.front()->value;
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            cout << val << endl;
            q.pop();
        }
    }

private:
    /*add value at leaf node */
    void appendLeft(Node *leaf, int value) { leaf->left = new Node(value); }
    void appendRight(Node *leaf, int value) { leaf->right = new Node(value); }
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
        if (n->left)
            child(n->left);

        if (n->right)
            child(n->right);

        cout << "Node : " << n->value << endl;
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
Node *addNode(Node *tree, int val)
{
    if (!tree)
    {
        tree = new Node(val);
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
        int choice = 0;

        cin >> choice;

        if (choice == 1)
        {
            int val;

            cout << "Enter new value to Add : ";
            cin >> val;
            root = addNode(root, val);
        }
        else if (choice == 2)
        {
            root->DFS();
        }
        else if (choice == 3)
        {
            root->BFS();
        }
        else if (choice == 4)
        {
            break;
        }
    }

    return 0;
}