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

Node *removeDuplicates(Node *head) // tricky ques
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;

    while (temp != NULL)  //in codestudio if use only temp.next then it not work but in vs work
    {
        Node *curr = temp;

        while (curr->next != NULL)                        
        {                                                   
            if (temp->data == curr->next->data)
            {
                Node *del = curr->next;
                curr->next = curr->next->next;
                delete del;
            }
            else
            {
                curr = curr->next;
            }
        }
        
        temp = temp->next;
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