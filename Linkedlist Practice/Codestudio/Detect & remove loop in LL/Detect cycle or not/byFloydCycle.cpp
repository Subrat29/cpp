#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Head Insert Function
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Tail Insert Function
void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d); // new node create
    tail->next = temp;
    tail = temp;
}

// Print Function
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



Node* Floyd_detectLoop(Node *head)   // tc: O(n) sc: O(1)
{  
    if(head == NULL)
    {
        return NULL;
    }

    Node *slow = head, *fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return slow;
        }
    }

    return NULL;
}


int main() // detect loop in singly linked lists.
{

    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 2);
    InsertAtHead(head, 3);
    InsertAtTail(tail, 9);
    InsertAtTail(tail, 8);

    tail->next = head;  // Create a loop

    cout << "tail: " << tail->data << endl;
    cout << "head: " << head->data << endl;

    if(Floyd_detectLoop(head) == NULL)
    {
        cout << "Loop is not present" << endl;
    }
    else
    {
        cout << "Loop is present at: " << Floyd_detectLoop(head)->data << endl << endl;
    }


    // print(head);

    return 0;
}