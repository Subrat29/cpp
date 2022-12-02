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

Node *reverseList(Node *head)
{
    //base condition
    if(head == NULL && head->next == NULL)
    return head;               
    
    //By recursive leap of faith
    Node *reverseHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return reverseHead;
}

int main()
{
    Node *head = NULL;
    InsertAthead(head, 1);
    InsertAthead(head, 2);
    InsertAthead(head, 3);
    InsertAthead(head, 4);
    print(head);

    //It reverse the original list ans gives us a new head
    print(reverseList(head));

    return 0;
}
