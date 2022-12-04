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

Node *removeDuplicates(Node *head) 
{
    if (head == NULL)
    {
        return NULL;
    }

     
}

int main()
{
    Node *head = NULL;
    InsertAtHead(head, -1);
    InsertAtHead(head, 7);
    InsertAtHead(head, 7);
    InsertAtHead(head, 2);
    InsertAtHead(head, 2);
    InsertAtHead(head, 2);
    InsertAtHead(head, 1);
    InsertAtHead(head, 2);
    InsertAtHead(head, 1);

    print(head);

    Node *dup = removeDuplicates(head);
    print(dup);

    return 0;
}