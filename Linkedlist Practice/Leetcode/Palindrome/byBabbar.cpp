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

Node* getMid(Node *head)
{
    Node *slow = head;
    Node *fast = slow->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reversePart(Node *head)
{
    Node *prev = NULL, *curr = head, *n = curr->next;
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = n;

        if(n != NULL)
        {
            n = n->next;   // Dry Run: if i am not using this then it work but in very last when n = null then n = n->next gives error 
        }
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    if(head->next == NULL)
    {
        return true;
    }

    //step 1 = find middle
    Node *mid = getMid(head);

    //step 2 = reverse list after middle
    Node *temp = mid->next;
    mid->next = reversePart(temp);

    //Step 3 = compare both halves
    Node *head1 = head;
    Node *head2 = mid->next;

    while (head2 != NULL)
    {
        if(head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    //step 4 = repeat step 2 bc to give list as it is input, it is not compulsory to do
    temp = mid->next;
    mid->next = reversePart(temp);

    return true;
}

int main()
{
    Node *head = NULL;
    InsertAthead(head, 1);
    InsertAthead(head, 2);
    InsertAthead(head, 3);
    InsertAthead(head, 3);
    InsertAthead(head, 2);
    InsertAthead(head, 1);
    print(head);

    if(isPalindrome(head))
    {
        cout << "yes palindrome";
    }
    else
    {
        cout << "Not palindrome";
    }

    return 0;
}
