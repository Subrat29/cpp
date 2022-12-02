#include <bits/stdc++.h>  //fraz
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

void InsertAthead(Node *&head, int d)
{
    Node *insert = new Node(d);
    insert->next = head;
    head = insert;
}

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

Node *mergeList(Node *head, Node *head1, Node *head2)
{
    Node *temp = head;
    Node *temp1 = head1;

    if(temp->data == temp1->data)
    {
        head2->data = temp->data;
        cout << head2->data << endl;
    }

    if(temp->data < temp1->data)
    {
        head2->data = temp->data;
    }
    else
    {
        head2->data = temp1->data;
    }
    return head2;
 
}

int main()
{
    Node *head = NULL;
    InsertAthead(head, 4);
    InsertAthead(head, 2);
    InsertAthead(head, 1);
    print(head);

    Node *head1 = NULL;
    InsertAthead(head1, 4);
    InsertAthead(head1, 3);
    InsertAthead(head1, 1);
    print(head1);

    Node *head2 = NULL;

    mergeList(head, head1, head2);
    print(head2);
    
    return 0;
}
