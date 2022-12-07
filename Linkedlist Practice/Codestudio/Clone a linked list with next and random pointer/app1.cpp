#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random; // random ptr is created

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->random = NULL;
    }
};

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

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

// Node *copyList(Node *head)        //We can't copy like this bc hm end me null ko new node maan rhe h;
// {
//     Node *copy = new Node(-1);
//     Node *temp = head;

//     while (temp != NULL)
//     {
//         copy = temp;
//         temp = temp->next;
//         copy = copy->next;        // here
//     }
//     return copy;
// }

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    // empy list
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

Node *copyList(Node *head)
{
    // step 1: create a clone list
    Node *clonehead = NULL;
    Node *clonetail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(clonehead, clonetail, temp->data);
        temp = temp->next;
    }

    // step 2: create a map
    unordered_map<Node *, Node *> oldToNewNode;

    Node *originalNode = head;
    Node *cloneNode = clonehead;

    while (originalNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // step 3: arrange all random pointers
    originalNode = head;
    cloneNode = clonehead;

    while (originalNode != NULL)
    {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return clonehead;
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

    Node *ans = copyList(head);
    print(ans);

    return 0;
}