#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    //Constructor
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

int findMiddle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data; 
}

int main()
{
    Node *head = NULL;
    InsertAthead(head, 6);
    InsertAthead(head, 5);
    InsertAthead(head, 4);
    InsertAthead(head, 3);
    InsertAthead(head, 2);
    InsertAthead(head, 1);
    print(head);

    cout << findMiddle(head);

    return 0;
}
