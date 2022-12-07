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
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseList(Node *head)  //tc: O(n) sc: O(n)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = reverseList(head->next);
    
    temp->prev = NULL;                     //dry run if not get
    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;

    return temp;
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

    // Node *rev = reverseList(head);
    print(reverseList(head));

    return 0;
}