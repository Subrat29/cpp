#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

// traversing a linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// length of a linked list
int getlength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// Insert at head
void Insertathead(Node *&head, Node *&tail, int d)
{
    // for empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Insert at tail
void Insertattail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Insert at position
void InsertAtposittion(Node *&head, Node *&tail, int position, int d)
{
    // Insert at first position
    if (position == 1)
    {
        Insertathead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Inserting at last position
    if (temp->next == NULL)
    {
        Insertattail(head, tail, d);
        return;
    }

    // Creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next = nodeToInsert;
    temp->next->prev = nodeToInsert;
}

int main()
{
    // Node *node1 = new Node(11);
    // Node *head = node1;
    // Node *tail = node1;

    Node *head = NULL;
    Node *tail = NULL;

    Insertathead(head, tail, 13);
    Insertathead(head, tail, 15);
    Insertattail(head, tail, 23);
    InsertAtposittion(head, tail, 1, 7);
    InsertAtposittion(head, tail, 2, 90);
    InsertAtposittion(head, tail, 3, 0);
    print(head);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    cout << getlength(head) << endl;

    return 0;
}