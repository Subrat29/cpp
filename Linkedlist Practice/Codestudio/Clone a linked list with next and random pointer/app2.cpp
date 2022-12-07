#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;            //random ptr is created

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
    //step 1: create a clone list
    Node *clonehead = NULL;
    Node *clonetail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(clonehead, clonetail, temp->data);
        temp = temp->next;
    }

    //step 2: add clonenode in b/w original node
    Node *originalNode = head;
    Node *cloneNode = clonehead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }


    //step 3: copy random pointer
    temp = head;
    while (temp != NULL)
    {
        if(temp->next != NULL)
        {
            // if(temp->random != NULL)
            // {
            //     temp->next->random = temp->random->next;
            // }
            // else
            // {
            //     temp->next = temp->random;
            // }

        temp->next->random = temp->random ? temp->random->next : temp->random;
        }

        //Now temp ko do baar badha do to visit next ptr of org list
        temp = temp->next->next;
    }

    // step 4: revert changes done in step 2
    originalNode = head;
    cloneNode = clonehead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if(originalNode != NULL)
        {
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }

    // step 5: return ans
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