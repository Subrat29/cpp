#include <bits/stdc++.h>  //sc O(n),  tc O(n)
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

Node* kReverse(Node* head, int k) {

    //base Case
    if(head == NULL && head->next == NULL)
    {
        return head;
    }

    //Step 1: reverse first k node
    int cnt = 0;
    Node *p = NULL, *c = head, *n = NULL;

    while (c != NULL && cnt < k)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;  
        cnt++;
    }

    //Step 2: recursion dekh lega aage
    if(n != NULL)
    head->next = kReverse(n,k);

    //Step 3: return head of reversed list
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

    int k = 2;
    print(kReverse(head, k));

    return 0;
}
