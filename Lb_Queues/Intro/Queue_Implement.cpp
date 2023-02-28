#include<iostream>
using namespace std;

class Queue
{
    int *arr;
    int qfront;  // compiler gets confused if u use same name for fn & var shows fn overloaded
    int rear;
    int size;

public:
    // constructor
    Queue()
    {                         // if we get no size in constructor
        size = 10001;         //intialize also int arr[10001]; 
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    
    int dequeue()
    {
        if(qfront == rear)
        {
            cout << "Empty queue";
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront ++;
            if(qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans; 
        }
    }

    int front()  
    {
        if(qfront == rear)
        {
            cout << "Empty queue";
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }

    bool isEmpty()
    {
        if(qfront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        for(int i=rear-1; i>=0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.print();

    q.dequeue();
    q.print();

    q.dequeue();
    q.print();

    q.dequeue();
    q.print();

    return 0;
}