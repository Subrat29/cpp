#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class Queue
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    //insert at tail
    void push(int d)
    {
        Node *temp = new Node(d);

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

    void pop()
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp != NULL)
                cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.print();

    q.pop();
    q.print();

    q.pop();
    q.print();

    q.pop();
    q.print();

    return 0;
}