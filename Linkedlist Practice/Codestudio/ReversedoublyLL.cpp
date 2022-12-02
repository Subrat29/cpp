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

// void reverseList(Node *&head)
// {
//     Node *c, *n, *tail;
    
//     c = head;
//     while (c != 0)
//     {
//         n = c->next;
//         c->next = c->prev;
//         c->prev = n;
//         c = n;
//     }
// }

/* Function to reverse a Doubly Linked List */
void reverse(Node* &head_ref)
{
    Node* temp = NULL;
    Node* current = head_ref;
 
    /* swap next and prev for all nodes of
    doubly linked list */
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
 
    /* Before changing the head, check for the cases like
       empty list and list with only one node */
    if (temp != NULL)
        head_ref = temp->prev;
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

    // print(reverseList(head));
    reverse(head);
    print(head);
    return 0;
}