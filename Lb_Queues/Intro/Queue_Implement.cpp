#include <bits/stdc++.h>
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



};

int main()
{

    return 0;
}