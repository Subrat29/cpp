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

Node *mergeList(Node *head1, Node *head2)   // by fraz
{
    //base condition
    if(head1 == NULL)
    return head2;

    if(head2 == NULL)
    return head1;

    if(head1->data < head2->data)
    {
        head1->next = mergeList(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = mergeList(head1, head2->next);
        return head2;
    }
}

int main()
{
    Node *head1 = NULL;
    InsertAthead(head1, 4);
    InsertAthead(head1, 2);
    InsertAthead(head1, 1);
    print(head1);

    Node *head2 = NULL;
    InsertAthead(head2, 4);
    InsertAthead(head2, 3);
    InsertAthead(head2, 1);
    print(head2);

    print(mergeList(head1, head2)) ;
    
    return 0;
}