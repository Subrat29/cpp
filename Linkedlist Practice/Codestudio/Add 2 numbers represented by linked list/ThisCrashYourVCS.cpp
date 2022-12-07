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

Node *reverse(Node *head)
{
    Node *prev = NULL, *curr = head, *n = NULL;
    while (curr != NULL)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
}

Node *insertAttail(Node *&head, Node *&tail, int digit)
{
    Node *temp= new Node(digit);

    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *add(Node *first, Node *second)
{
    int carry = 0;
    
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL && second != NULL)
    {
        int sum = carry + first->data + second->data;
        int digit = sum % 10;

        //create node and add in answer Linked Lists
        insertAttail(ansHead, ansTail, digit);
        
        carry = sum / 10;
    }

    while (first != NULL)
    {
        int sum = carry + first->data;
        int digit = sum % 10;
        insertAttail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    while (second != NULL)
    {
        int sum = carry + second->data;
        int digit = sum % 10;
        insertAttail(ansHead, ansTail, digit);
        carry = sum / 10;
    }
    
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        insertAttail(ansHead, ansTail, digit);
        carry = sum / 10;
    }
    
    return ansHead;
}

Node *addList(Node *first, Node *second)
{
    //step 1 = reverse input lists
    first = reverse(first);
    second = reverse(second);

    //step 2 = add lists
    Node *ans = add(first, second);

    //step 3 = reverse ans
    ans = reverse(ans);

    return ans;
}

int main()
{
    Node *first = NULL;
    InsertAthead(first, 5);
    InsertAthead(first, 4);
    print(first);

    Node *second = NULL;
    InsertAthead(second, 5);
    InsertAthead(second, 4);
    InsertAthead(second, 3);
    print(second);

    print(addList(first,second));

    return 0;
}