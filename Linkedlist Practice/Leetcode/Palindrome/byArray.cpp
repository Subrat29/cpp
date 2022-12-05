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

bool isPalindrome(Node *head, int a[], int b[], int l)   // tc: O(n), sc: O(n)
{
    int i=0;
    Node *temp = head;

    while (temp != NULL)
    {
        a[i++] = temp->data;
        temp = temp->next;
    } 

    for(int i=0; i<l; i++)
    {
        b[l-i-1] = a[i];
    }              

    for(int i=0; i<l; i++)
    {
        if(b[i] != a[i])
        {
            return false;
        }
    }
    return true;
}

int getlength(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main()
{
    int a[50], b[50];
    Node *head = NULL;
    InsertAthead(head, 1);
    InsertAthead(head, 2);
    InsertAthead(head, 2);
    InsertAthead(head, 1);

    int l = getlength(head);
    print(head);

    if(isPalindrome(head, a, b, l))
    cout << "yes, palindrome";
    else
    cout << "Not palindrome";

    return 0;
}
