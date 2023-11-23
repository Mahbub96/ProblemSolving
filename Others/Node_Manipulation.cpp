#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *addNode(Node *head)
{
    int data;
    cout << "Enter new Data for new Next Node : ";
    cin >> data;
    Node *temp = head;
    if (!temp)
    {
        head = new Node(data);
        return head;
    }

    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);

    return head;
}

void printNode(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << temp->data << endl;
}

/*
void printPostorder(struct Node *node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);

    printPostorder(node->right);

    cout << node->data << " ";
}

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    cout << node->data << " ";

    printInorder(node->right);
}

void printPreorder(struct Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";

    printPreorder(node->left);

    printPreorder(node->right);
}
Node *root = NULL;
*/
int main()
{
    Node *n;
    int choice;
    do
    {

        cout << "\n\t1.add value\n\t2.view\n\t3.Exit\n\n\tEnter Your choice: ";
        cin >> choice;

        if (choice == 1)
            n = addNode(n);
        else if (choice == 2)
            printNode(n);
        // system("clear");
    } while (choice != 3);
    return 0;
}
