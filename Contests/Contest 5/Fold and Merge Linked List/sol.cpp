#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void inserAttail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

Node *findMiddle(Node *head)
{
    Node *slow = head, *fast = head->next;

    while (fast->next != NULL)
    {
        slow = head;
        fast = head->next;
    }
    return slow;
}

void reverseList1(Node *&list1)
{
    Node *prev = NULL, *curr = list1;

    while (curr->next != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
}

Node *foldAndMerge(Node *head)
{
    //step 1: find middle node
    Node *middle = findMiddle(head);

    //step 2: devide list in 2 halves
    Node *list1 = head;
    Node *list2 = middle->next;
    middle->next = NULL;

    //step 3: reverse list1
    reverseList1(list1);

    //step 4: product list1 & list2
    Node *temp = list1;
    while (temp != NULL)
    {
        temp->data = list1->data * list2->data;
        temp = temp->next;

        temp = temp->next;
        list1 = list1->next;
        list2 = list2->next;
    }
    return list1;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *list = new Node(1);
    Node *head = list;
    Node *tail = list;

    inserAttail(tail, 2);
    inserAttail(tail, 3);
    inserAttail(tail, 4);
    inserAttail(tail, 5);
    inserAttail(tail, 6);

    Node *ans = foldAndMerge(head);
    print(ans);

    return 0;
}