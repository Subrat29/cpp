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

bool isPalindrome(vector <int> a)   // tc: O(n), sc: O(n)
{
    int l = a.size();
    int s=0, e = l-1;

    while (s < e)
    {
        if(a[s] != a[e])
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }  
    return true; 
}

int main()
{
    vector <int> a;

    Node *head = NULL;
    InsertAthead(head, 1);
    InsertAthead(head, 9);
    InsertAthead(head, 9);
    InsertAthead(head, 1);
    print(head);

    Node *temp = head;
    while (temp != NULL)
    {
        a.push_back(temp->data);
        temp = temp->next;
    }

    if(isPalindrome(a))
    {
        cout << "yes palindrome";
    }
    else
    {
        cout << "Not palindrome";
    }

    return 0;
}
