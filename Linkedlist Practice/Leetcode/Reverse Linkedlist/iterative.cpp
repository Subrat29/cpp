#include <bits/stdc++.h> //fraz sc O(n),  tc O(1)
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
    if (head == NULL || head->next == NULL)              // mistake  use &&
        return head;

    Node *prev = NULL, *curr = head, *next = NULL;       // class Node wala next arrow se diffrentiate ho rha h maybe

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    Node *head = NULL;
    InsertAthead(head, 1);
    InsertAthead(head, 2);
    InsertAthead(head, 3);
    InsertAthead(head, 4);
    print(head);

    // It reverse the original list ans gives us a new head
    print(reverseList(head));

    // print(head);
    // print(head->next);

    return 0;
}
