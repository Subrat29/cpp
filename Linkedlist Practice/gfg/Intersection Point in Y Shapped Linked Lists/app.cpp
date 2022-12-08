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

Node *insertAttail(Node *&head, Node *&tail, int digit)
{
    Node *temp = new Node(digit);

    if (head == NULL)
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

int getIntesectionNode(Node* head1, Node* head2)
{
 
    // Count the number of nodes in
    // both the linked list
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
 
    // If first is greater
    if (c1 > c2) {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}
 
/* function to get the intersection point of two linked
lists head1 and head2 where head1 has d more nodes than
head2 */
int _getIntesectionNode(int d, Node* head1, Node* head2)
{
    // Stand at the starting of the bigger list
    Node* current1 = head1;
    Node* current2 = head2;
 
    // Move the pointer forward
    for (int i = 0; i < d; i++) {
        if (current1 == NULL) {
            return -1;
        }
        current1 = current1->next;
    }
 
    // Move both pointers of both list till they
    // intersect with each other
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2)
            return current1->data;
 
        // Move both the pointers forward
        current1 = current1->next;
        current2 = current2->next;
    }
 
    return -1;
}
 
/* Takes head pointer of the linked list and
returns the count of nodes in the list */
int getCount(Node* head)
{
    Node* current = head;
 
    // Counter to store count of nodes
    int count = 0;
 
    // Iterate till NULL
    while (current != NULL) {
 
        // Increase the counter
        count++;
 
        // Move the Node ahead
        current = current->next;
    }
 
    return count;
}

int main()
{
    Node *first = NULL;
    InsertAthead(first, 5);
    InsertAthead(first, 4);
    InsertAthead(first, 7);
    InsertAthead(first, 2);
    InsertAthead(first, 1);
    print(first);

    Node *second = NULL;
    InsertAthead(second, 5);
    InsertAthead(second, 4);
    InsertAthead(second, 3);
    print(second);

    cout << getIntesectionNode(first, second);

    return 0;
}