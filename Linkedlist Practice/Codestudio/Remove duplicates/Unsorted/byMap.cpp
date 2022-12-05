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

// insert by head
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// print the list
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

// Is ke syntax aage padna h so no tense here bro
Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    unordered_set<int> seen; 
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)  //we not use curr->next != NULL bec if curr is on last node but last node is duplicate then it cant come in loop to delete node bc of condn.
    {
        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
    return head;
}

int main()
{
    Node *head = NULL;
    InsertAtHead(head, -1);
    InsertAtHead(head, 7);
    InsertAtHead(head, 7);
    InsertAtHead(head, 2);
    InsertAtHead(head, 2);
    InsertAtHead(head, 2);
    InsertAtHead(head, 1);
    InsertAtHead(head, 2);
    InsertAtHead(head, 1);

    print(head);

    Node *dup = removeDuplicates(head);
    print(dup);

    return 0;
}