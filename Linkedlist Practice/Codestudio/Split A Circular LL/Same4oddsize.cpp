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

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data: " << value << endl;
    }
};

void insertion(Node *&head, int element, int d)
{
    if (head == NULL)
    {
        Node *newNode = new Node(d);
        head = newNode;
        newNode->next = newNode;
    }
    else
    { 
        Node *curr = head;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *head)
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    do
    {
        cout << head->data << " ";
        head = head->next;
    } while (head != temp);

    cout << endl;
}

void splitCircularList(Node *&head)
{
    Node *temp = head, *tail;
    int cnt = 0;
    do
    {
        cnt++;
        tail = temp;       //ye dry run pr hi ayega bro
        temp = temp->next;
    } while (temp != head);

    for(int i=1; i<cnt/2; i++)
    {
        temp = temp->next;
    }

    Node *second = temp->next; 
    tail->next = temp->next;

    Node *first = head;
    temp->next = head;

    print(first);
    print(second);
}


int main()
{
    Node *head = NULL;


    insertion(head, 5, 3);    
    insertion(head, 3, 6);
    insertion(head, 6, 7);
    insertion(head, 7, 8);
    insertion(head, 8, 9);
    print(head);

    splitCircularList(head);

    return 0;
}