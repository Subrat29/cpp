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

void isPalindrome(Node *head)
{
    int a[100], b[100], i=0;
    Node *temp = head;
    while (temp != NULL)
    {
        a[i++] = temp->data;
        temp = temp->next;
    }                                               

    int l = sizeof(a)/sizeof(a[0])-1;
    cout << "L : " << l << endl;
    for(int i=0; i<=l; i++)
    {
        b[l-i] = a[i];
    }

    int flag;
    for(int i=0; i<=l; i++)
    {
        if(b[i] == a[i])
        {
        cout << "a[i]: " << a[i] << "  ";
        cout << "b[i]: " << b[i] << endl;
        flag = 0;
        }
        else
        flag = 1;
    }

    if(flag == 0)
    cout << "Palindrome h bro";
    else
    cout << "palindrome nhi h";
}

int main()
{
    Node *head = NULL;
    InsertAthead(head, 1);
    InsertAthead(head, 2);
    InsertAthead(head, 1);
    print(head);

    isPalindrome(head);

    return 0;
}
