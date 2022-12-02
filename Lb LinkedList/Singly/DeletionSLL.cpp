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

    //Distructor
    ~Node()
    {
        int value = this->data;
        //Memory free
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free of " << value << endl;

    }

};

    //Tail Insert Function
    void InsertAtTail(Node* &tail, int d)
    {
        Node* temp = new Node(d); //new node create
        tail->next = temp;
        tail = temp;
        cout << " TAIL DATA: " << tail->data << endl;
    }

    //Deletion in function
    void deleteNode(int position, Node* & head)
    {
        // 1) Deleting starting node
        if(position == 1)
        {
            Node*temp = head;
            head = head->next;
            //start node memory free
            temp->next = NULL;
            delete temp;     
        }
        else
        {
            // 2) Deleting any middle node or last node
            Node* curr = head;
            Node* prev = NULL;

            int cnt=1;
            while (cnt < position)
            {
                prev = curr;
                curr = curr->next;
                cnt++;
            }

            prev-> next = curr->next;
            curr->next = NULL;
            delete curr; 
             
        }
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

Node* node1 = new Node(10);
Node* head = node1;
Node* tail = node1;
InsertAtTail(tail,4); 
InsertAtTail(tail,9);
InsertAtTail(tail,5);
InsertAtTail(tail,7);
print(head);

cout << "head: " << head->data << endl;
cout << "tail: " << tail->data << endl;  // In this line a mistake tail ki jagah mene head likh diya tha = solved

deleteNode(1,head);

print(head);
cout << "head: " << head->data << endl;  //tail wrong posn bata rha h bro = solved
cout << "tail: " << tail->data << endl;

    return 0;
}