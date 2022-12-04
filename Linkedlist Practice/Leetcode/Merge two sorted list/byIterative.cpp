#include <bits/stdc++.h> //fraz
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

Node *mergeList(Node *head1, Node *head2)  //by fraz
{
    // base condition
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node *ans = new Node(-1);
    Node *tail = ans;                   // tail is important otherwise only last 2 node is print

    while (head1 != NULL && head2 != NULL)
    {

        if (head1->data < head2->data)
        {
            tail->next = head1;
            tail = tail->next;     //forgot this
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = tail->next;     //forgot this
            head2 = head2->next;
        }
    }

    if(head1 == NULL)
    tail->next = head2;
    else
    tail->next = head1;

    return ans->next;
}

int main()
{
    Node *head1 = NULL;
    InsertAthead(head1, 3);
    InsertAthead(head1, 2);
    InsertAthead(head1, 1);
    print(head1);

    Node *head2 = NULL;
    InsertAthead(head2, 4);
    InsertAthead(head2, 3);
    InsertAthead(head2, 1);
    print(head2);

    print(mergeList(head1, head2));

    return 0;
}