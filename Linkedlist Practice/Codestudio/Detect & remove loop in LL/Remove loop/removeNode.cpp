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
    Node *temp = new Node(d);
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

Node *Floyd_detectLoop(Node *head)
{
    if (head == NULL)
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

Node *startingNode(Node *head) // finding starting node of a loop
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *intersection = Floyd_detectLoop(head);

    if(intersection == NULL)
    {
        return NULL;
    }

    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node* removeLoop(Node *head) //remove loop from list
{
    Node *LoopStartnode = startingNode(head);

    if(LoopStartnode == NULL)
    {
        return head;
    }

    Node *temp = LoopStartnode;

    while (temp->next != LoopStartnode)
    {
        temp = temp->next;
    }
    temp->next = NULL;

    cout << "Remove Loop completed" << endl;

    return head;
}


int main() // detect loop in singly linked lists.
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    InsertAtTail(tail, 9);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 4);
    InsertAtTail(tail, 7);

    tail->next = head; // Create a loop

    // print(head);

    cout << "tail: " << tail->data << endl;
    cout << "head: " << head->data << endl << endl;

    if (Floyd_detectLoop(head) == NULL)
    {
        cout << "Loop is not present" << endl;
    }
    else
    {
        cout << "Loop is present" << endl;
    }


    cout << "Starting Node of Loop: " << startingNode(head)->data << endl << endl;

    Node *removeLooplist = removeLoop(head);


    if (Floyd_detectLoop(head) == NULL)
    {
        cout << "Loop is not present" << endl << endl;
    }
    else
    {
        cout << "Loop is present" << endl << endl;
    }

    print(removeLooplist);

    return 0;
}