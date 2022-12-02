#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    //Constructor
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

void storeList(Node *head, string s)
{
    Node *temp = head;
    int i=0;
    while(temp != NULL)
    {
        s[i] = temp->data;
        temp = temp->next;
        i++;
    }
}

int main()
{
    Node *head = NULL;
    InsertAthead(head, 3);
    InsertAthead(head, 4);
    InsertAthead(head, 5);
    print(head);

    string s;
    storeList(head,s);
    

    return 0;
}
