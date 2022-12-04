#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

// insert by head
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// print the list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *sortList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    int zeroCount = 0, oneCount = 0, twoCount = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }

        if (temp->data == 1)
        {
            oneCount++;
        }

        if (temp->data == 2)
        {
            twoCount++;
        }

        temp = temp->next;
    }

    temp = head;
    while (zeroCount--)
    {
        temp->data = 0;
        temp = temp->next;
    }

    while (oneCount--)
    {
        temp->data = 1;
        temp = temp->next;
    }

    while (twoCount--)
    {
        temp->data = 2;
        temp = temp->next;
    }

    return head;
}

int main()
{
    Node *head = NULL;
    InsertAtHead(head, 2);
    InsertAtHead(head, 1);
    InsertAtHead(head, 1);
    InsertAtHead(head, 2);
    InsertAtHead(head, 0);
    print(head);

    Node *sortHead = sortList(head);
    print(sortHead);

    return 0;
}