#include <iostream>

using namespace std;

/* Pure Binary tree */

class Node
{
    int value;
    Node *left;
    Node *right;

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
    void show()
    {
        Node *currentNode = this;
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
    Node *root = new Node(8);

    root->append(5);
    root->append(9);
    root->append(3);
    root->append(1);
    root->append(7);
    root->append(4);
    root->append(10);
    root->append(6);
    root->append(5);

    root->show();
    return 0;
}