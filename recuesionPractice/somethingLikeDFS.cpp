#include <iostream>
#include <typeinfo>

using namespace std;

/* Pure Binary tree */

class Node
{
    int value;
    Node *left;
    Node *right;

public:
    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
    Node()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }

private:
    Node *findAppropiatePosition(Node *n, int &val)
    {
        if (val <= n->value)
        {
            cout << "Val : " << val << " for left node of : " << n->value << endl;
            if (n->left)
                findAppropiatePosition(n->left, val);
        }
        else
        {
            cout << "Val : " << val << " for right node of : " << n->value << endl;
            if (n->right)
                findAppropiatePosition(n->right, val);
        }
        return n;
    }

public:
    void append(int val)
    {

        Node *last = findAppropiatePosition(this, val);

        if (val <= last->value)
            appendLeft(val);
        else
            appendRight(val);
    }

private:
    void appendLeft(int value)
    {
        Node *leaf = this;

        while (leaf->left)
        {
            leaf = leaf->left;
        }
        leaf->left = new Node(value);
    }

    void appendRight(int value)
    {
        Node *leaf = this;

        while (leaf->right)
        {
            leaf = leaf->right;
        }
        leaf->right = new Node(value);
    }

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

public:
    void DFS()
    {
        Node *currentNode = this;
        if (!currentNode)
        {
            cout << "No node found!" << endl;
            return;
        }
        cout << "Root : " << currentNode->value << endl;

        while (currentNode)
        {
            if (currentNode->left)
            {
                currentNode = showLeft(currentNode);
            }
            else if (currentNode->right)
            {
                currentNode = showRight(currentNode);
            }
            else
                break;
        }
    }
};

int main()
{
    Node *root = new Node(30);

    while (true)
    {
        cout << "\n\n\t\t[Admin Panal of Node Example Console]\n\t1.Add New Node.\t2.DFS\n\t3.BFS\t\t4.Exit \n\nEnter your choice : ";
        int choice = 0;

        cin >> choice;
        if (choice == 1)
        {
            cout << typeid(typeid(choice).name()).name() << endl;
            int val;

            cout << "Enter new value to Add : ";
            cin >> val;
            if (isdigit(val))
                root->append(val);
            else
                cout << "Please Enter an Integer value";
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