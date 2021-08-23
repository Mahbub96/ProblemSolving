#include <iostream>

using namespace std;

/* Pure Binary tree */

class Node
{
    int value;
    Node *left;
    Node *right;

    /** Start Input Sector **/

    /* find leaf node to add new value */
    Node *findAppropiatePosition(Node *n, int &val)
    {
        bool running = true;
        while (running)
        {

            if (val <= n->value)
            {

                cout << "Value : " << val << " goes to left node of : " << n->value << endl;
                if (n->left)
                    n = n->left;
                else
                    running = false;
            }
            else
            {

                cout << "Value  : " << val << " goes to right node of : " << n->value << endl;
                if (n->right)
                    n = n->right;
                else
                    running = false;
            }
        }
        return n;
    }

public:
    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
    /*add value at leaf node */
    void append(int val)
    {
        Node *last = findAppropiatePosition(this, val);
        if (val <= last->value)
            appendLeft(last, val);
        else
            appendRight(last, val);
    }

private:
    void appendLeft(Node *leaf, int value) { leaf->left = new Node(value); }
    void appendRight(Node *leaf, int value) { leaf->right = new Node(value); }

    /** End Input Sector **/

    /** Start DFS Sector **/

    Node *showLeft(Node *n)
    {
        n = n->left;
        cout << "Left : " << n->value << endl;
        return n;
    }
    Node *showRight(Node *n)
    {
        n = n->right;
        cout << "right : " << n->value << endl;
        return n;
    }

    /*recurrent function for DFS of this tree*/
    void child(Node *n)
    {
        if (n->left)
            child(n->left);

        if (n->right)
            child(n->right);

        cout << "Node : " << n->value << endl;
    }

public:
    void DFS()
    {
        if (this)
            child(this);
        else
            cout << "Node is Empty!" << endl
                 << endl;
    }
};

Node *addNode(Node *tree, int val)
{

    if (!tree)
    {
        tree = new Node(val);
        system("clear");
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
        }
        else if (choice == 4)
        {
            break;
        }
    }

    return 0;
}