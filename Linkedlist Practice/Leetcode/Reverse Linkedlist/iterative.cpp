#include <bits/stdc++.h>  //fraz sc O(n),  tc O(1)
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

void InsertAthead(Node *&head, int d)
{
    Node *insert = new Node(d);
    insert->next = head;
    head = insert;
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

Node *reverseList(Node *head)
{
    if (head == NULL && head->next == NULL)
        return head;

    Node *p = NULL, *c = head, *n = c->next;  // previous, current , current ka next

    while (c != NULL)
    {
        c->next = p;
        p = c;
        c = n;
        if (n != NULL)
        {
            n = n->next;   // Dry Run: if i am not using this then it work but in very last when n = null then n = n->next gives error 
        }  
    }
    return p;
}

int main()
{
    Node *head = NULL;
    InsertAthead(head, 1);
    InsertAthead(head, 2);
    InsertAthead(head, 3);
    InsertAthead(head, 4);
    print(head);

    //It reverse the original list ans gives us a new head
    print(reverseList(head));

    // print(head);
    // print(head->next);

    return 0;
}
