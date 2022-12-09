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

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *getMid(Node *head)
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

Node *merge(Node *left, Node *right)
{
    if(left == NULL)
    {
        return right;
    }

    if(right == NULL)
    {
        return left;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;

    //merge 2 sorted linked list
    while (left != NULL && right != NULL)
    {
        if(left->data < right->data)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }

        temp = temp->next;
    }
    
    // if (left == NULL)
    // {
    //     temp->next = right;
    // }

    // if (right == NULL)
    // {
    //     temp->next = left;
    // }

    if (left != NULL)
    {
        temp->next = left;
    }

    if (right != NULL)
    {
        temp->next = right;
    }

    return ans;
}

Node *Mergesort(Node *head)
{
    //base case
    if(head == NULL && head->next == NULL)
    {
        return head;
    }

    //get mid
    Node *mid = getMid(head);

    //break list in 2 halves
    Node *right = head;
    Node *left = mid->next;
    mid->next = NULL;

    //sort these 2 halves by recursion
    right = Mergesort(right);
    left = Mergesort(left);

    //merge these 2 halves
    Node *result = merge(left, right);
    return result;
}

int main()
{
    Node *head = NULL;
    InsertAtHead(head, 4);
    InsertAtHead(head, 1);
    InsertAtHead(head, 7);
    InsertAtHead(head, 6);
    InsertAtHead(head, 2);
    print(head);

    Node *ans = Mergesort(head);
    print(ans);

    return 0;
}