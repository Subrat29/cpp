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

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data: " << value << endl;
    }
};

void insertion(Node *&tail, int element, int d)  //insertion kisi elem ke adhar pr kiya h yha
{
    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    { // Non empty list
        // Assume that element is present in list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // Element found and now curr is showing that element
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    Node *temp = tail;

    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }

    else
    {
        // non empty
        // assuming that value is print in list
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node Linked list
        if (curr = prev)
        {
            tail = NULL;
        }

        // >=2 node linked list
        if (tail == curr)
        {
            tail = prev; // How it works ???
        }

        curr->next = NULL;
        delete curr;
    }
}

bool detectLoop(Node *tail)
{
    if(tail == NULL)
    {
        return false;
    }

    map <Node*,bool> visited;   //create a map Node is key, bool is value
    Node *temp = tail;

    while (temp != NULL)
    {
        //cycle is present 
        if(visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *tail = NULL;

    insertion(tail, 5, 3);
    insertion(tail, 3, 6);
    insertion(tail, 1, 7);
    insertion(tail, 2, 8);

    print(tail);

    if(detectLoop(tail))
    {
        cout << "Cycle is present";
    }
    else
    {
        cout << "Cycle is not present";
    }
    return 0;
}