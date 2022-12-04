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

// insert by head
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// print the list
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

void insertatTail(Node *temp, Node *&tail)
{
    tail->next = temp;
    tail = temp;
}

Node *sortList(Node *head)              // If data replacement is not allowed in list then use this approach. tc: O(n), sc: O(1)
{
    Node *Zerohead = new Node(-1);
    Node *zerotail = Zerohead;

    Node *Onehead = new Node(-1);
    Node *onetail = Onehead;

    Node *Twohead = new Node(-1);
    Node *twotail = Twohead;

    Node *temp = head;


    //Create seperate list 0s, 1s, 2s
    while (temp != NULL)
    {
        int value = temp->data;

        if(value == 0)
        {
            insertatTail(temp, zerotail);
        }

        else if(value == 1)
        {
            insertatTail(temp, onetail);
        }

        else if(value == 2)
        {
            insertatTail(temp, twotail);
        }

        temp = temp->next;
    }

    // print(Zerohead); why these nodes gives wrong answer
    // print(Onehead);
    // print(Twohead);

    //merge 3 sublist

    //1s list is not empty
    if(Onehead->next != NULL)
    {
        zerotail->next = Onehead->next;
        onetail->next = Twohead->next;
    }
    else
    {
        //1s list is empty
        zerotail->next = Twohead->next;
    }

    //onetail->next = Twohead->next;
    twotail->next = NULL;

    //Head setup
    head = Zerohead->next;

    //delete dummy nodes
    delete Zerohead;
    delete Onehead;
    delete Twohead;

    return head;
}

int main()
{
    Node *head = NULL;
    InsertAtHead(head, 2);
    InsertAtHead(head, 1);
    InsertAtHead(head, 1);
    InsertAtHead(head, 2);
    InsertAtHead(head, 0);
    print(head);

    Node *sort = sortList(head);
    print(sort);

    return 0;
}