#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool isCircular(Node *head)
{

    if (head == NULL)
        return true;
    Node *temp = head->next;
    while (temp != head && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp == head)
        return true;
    else
        return false;
}

int main()
{
    Node *head = NULL;  //Now insert some data in node

    isCircular(head);
    return 0;
}
