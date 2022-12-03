#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // this is pointer of Node type whose mame is next

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

// find the node and print the index
int findNode(Node *head, int n)
{
    Node *temp = head;
    int count = 0;

    // while (temp->data != n && temp != NULL)
    while (temp && temp->data != n)
    {
        temp = temp->next;
        count++;
    }

    // if (temp->data == n)
    if (temp && temp->data == n)
    {
        return count;
    }
    else
    {
        return -1;
    }
}

// insert a node in Linked list by head
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d); // new node create
    temp->next = head;        // temp ke ptr me head
    head = temp;              // head me NUll
}

// print the list
void print(Node *&head)
{
    Node *temp = head; // Create a node temp
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    InsertAtHead(head, 4);
    InsertAtHead(head, 9);
    InsertAtHead(head, 7);
    InsertAtHead(head, 3);
    InsertAtHead(head, 2);
    print(head);

    int ans = findNode(head, 34);
    cout << ans << endl;

    return 0;
}