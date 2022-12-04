#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertHead(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (head != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseList(Node *head)
{
    Node *c = head, *n = NULL;

    while (c != 0)
    {
        n = c->next;
        c->next = c->prev;
        c->prev = n;
        c = n;
    }
    return head;
}


int main()
{
    Node *head = NULL;
    insertHead(head, 1);
    insertHead(head, 2);
    insertHead(head, 3);
    insertHead(head, 4);
    insertHead(head, 5);
    print(head);

    Node *rev = reverseList(head);
    print(rev);

    return 0;
}