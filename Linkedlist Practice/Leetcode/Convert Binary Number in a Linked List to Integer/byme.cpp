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

void storeList(Node *head, int *arr)
{
    Node* temp = head;
    int i=0;
    while (temp != NULL)
    {
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    } 
}

int convertBinarytoDecimal(int arr[])
{
    int l = sizeof(arr)/sizeof(arr[0]);
    int decimal = 0;
    int base = 1;

    for(int i=l-1; i>=0; i--)
    {
        if(arr[i] == 1)
        decimal = decimal + base;
        base  = base*2;
    }
    return  decimal;
}

int main()
{
    int arr[100];
    Node *head = new Node(1);
  //Node* head = new Node(7);  error: head previousy declared
    InsertAthead(head, 0);
    InsertAthead(head, 1);
    print(head);
    storeList(head,arr);
    cout << convertBinarytoDecimal(arr);

    return 0;
}