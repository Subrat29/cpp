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

int findBinary(Node *head)
{
    Node *temp = head;
    int ans = 0;
    while (temp != NULL)
    {
        ans *= 2;
        ans += temp->data;
        temp = temp->next;
    }
    return ans;
}

int main()
{
    int arr[100];
    Node *head = new Node(1);
    InsertAthead(head, 1);
    InsertAthead(head, 1);
    print(head);

    cout << findBinary(head);
    return 0;
}