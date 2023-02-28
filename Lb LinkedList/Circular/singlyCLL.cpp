#include<iostream>
#include<map>
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

//Insertion krne pr hi hm node ko cirular banate h , pls dry run
void insertion(Node *&tail, int element, int d)   // insertion kisi elem ke behaf pr kiya h yha jo list me present ho exept intial insert.
{
    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;                   // why not said this tail...head = tail
        newNode->next = newNode;
    }
    else
    { // Non empty list
        // Assume that element is present in list
        Node *curr = tail;                                    //Actually, me ye head hua na ki tail if u traverse, or both is just same thing
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

    // empty list
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
        if (curr == prev)
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

bool isCircularList(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

bool detectLoop(Node *tail)
{
    if (tail == NULL)
    {
        return false;
    }

    map<Node *, bool> visited; // create a map Node is key, bool is value
    Node *temp = tail;

    while (temp != NULL)
    {
        // cycle is present
        if (visited[temp] == true)
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

    insertion(tail, 5, 3);     //yhi pr mistake hogi bc hm insert elem ke behaf pr krrhe h, carefull vo elem present bhi hona chahiye
    insertion(tail, 3, 6);
    insertion(tail, 6, 7);
    insertion(tail, 7, 8);
    
    
    print(tail);

    // tail->next = NULL;  // switch to convert circular and non-circular

    if (isCircularList(tail))
    {
        cout << "Linked List is Circular in nature" << endl;
    }
    else
    {
        cout << "Linked List is not Circular " << endl;
    }

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