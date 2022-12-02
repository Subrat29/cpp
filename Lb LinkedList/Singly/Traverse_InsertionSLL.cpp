#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};


// NOTE: Write function outside the class only

    //Head Insert Function
    void InsertAtHead(Node* &head, int d)
    {
        Node* temp = new Node(d); //new node create
        temp->next = head; // temp ke ptr me head
        head = temp; // head me NUll 
    }

    //Tail Insert Function
    void InsertAtTail(Node* &tail, int d)
    {
        Node* temp = new Node(d); //new node create
        tail->next = temp;
        tail = temp;
    }

    //Any position Insert Function
    void InsertAtposittion(Node* &tail, Node* &head, int position, int d)
    {
        //Insert at first position
        if(position == 1)
        {
            InsertAtHead(head,d);
            return;
        }

        Node*temp = head;
        int cnt = 1;
        while (cnt < position-1)
        {
            temp = temp->next;
            cnt++;
        }

        //Inserting at last position
        if(temp->next == NULL)
        {
            InsertAtTail(tail,d);
            return;
        }
        //Creating a node for d
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;

    }

    //Print Function
    void print(Node* &head)
    {
        Node* temp = head; // Create a node temp
        while (temp != NULL)
        {
            cout << temp->data << " " ;
            temp = temp->next;
        }
        cout << endl;
    }


int main()
{
    //Node* node1 = new Node(1);    //Create an object in heap
    //cout << node1->data << endl;
    //cout << node1->next << endl;

/* // Head Insertion

    Node* head = node1;   //Head pointed to node1
    print(head);
    InsertAtHead(head, 2);
    print(head);
    InsertAtHead(head, 3);
    print(head);
*/

/* // Tail Insertion

Node* node1 = new Node(1);
Node* head = node1;
Node* tail = node1;
InsertAtTail(tail,4); 
InsertAtTail(tail,9);
print(head);
*/

//Insertion at any point
Node* node1 = new Node(1);
Node* head = node1;
Node* tail = node1;
InsertAtHead(head, 2);
InsertAtHead(head, 3);
print(head);
InsertAtposittion(tail,head,1,7);
print(head);

    return 0;
}