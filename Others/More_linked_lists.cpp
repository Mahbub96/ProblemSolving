// Incomplete Code of Day 24 at hackerRank

#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

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
class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {

        // Write your code here
        Node *ptr1, *ptr2, *dup;
        ptr1 = head;
        while (ptr1)
        {
            ptr2 = ptr1;
            while (ptr2->next)
            {
                if (ptr1->data == ptr2->next->data)
                {
                    dup = ptr2->next;
                    ptr2->next = dup->next;
                    delete (dup);
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
        return head;
    }

    Node *insert(Node *head, int data)
    {
        Node *p = new Node(data);
        if (head == NULL)
        {
            head = p;
        }
        else if (head->next == NULL)
        {
            head->next = p;
        }
        else
        {
            Node *start = head;
            while (start->next != NULL)
            {
                start = start->next;
            }
            start->next = p;
        }
        return head;
    }
    void display(Node *head)
    {
        Node *start = head;
        while (start)
        {
            cout << start->data << " ";
            start = start->next;
        }
    }
};

int main()
{
    Node *head = NULL;
    Solution mylist;
    int T, data;
    cin >> T;
    while (T-- > 0)
    {
        cin >> data;
        head = mylist.insert(head, data);
    }
    head = mylist.removeDuplicates(head);

    mylist.display(head);
}