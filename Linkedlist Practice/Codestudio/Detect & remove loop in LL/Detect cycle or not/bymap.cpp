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

void insertion(Node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {   // Non empty list
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

//sc O(n), tc(n)

bool detectLoop(Node *tail) //detect loop in a cicular linked list,and we know that one cycle is present in cll.
{
    if(tail == NULL)
    {
        return false;
    }

    map <Node*,bool> visited; //create a map: Node is key, bool is value.
    Node *temp = tail;

    while (temp != NULL)
    {
        //cycle is present 
        if(visited[temp] == true)
        {
            cout << "Cycle is at: " << temp->data << endl;
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

    insertion(tail, 0, 1);
    insertion(tail, 1, 2);
    insertion(tail, 2, 3);
    insertion(tail, 3, 4);
    print(tail);
    cout << endl;
    
    cout << tail->data << endl;

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