#include<iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    // constructor
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool enqueue(int value)
    {
        //to check queue is full or not
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) )   // mistake ==
        {
            //cout << "queue is full" << endl;
            return false;
        }

        else if (front == -1)  //first elem to push
        {
            front = rear = 0;
        }

        else if (rear == size - 1 && front != 0)                  //mistake i use || instead &&
        {
            rear = 0;         //to maintain cyclic nature
        }

        else
        {
            rear++;          //normal flow
        }

        arr[rear] = value;    //push inside
        return true;
    }

    int dequeue()
    {
        if(front == -1)       //to check queue is empty or not
        {
            //cout << "Empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if(front == rear)     //if single elem is present
        {
            front = rear = -1;
        }

        else if(front == size-1)
        {
            front = 0;        //to maintain cyclic nature
        }
        else
        {
            front++;          //normal flow
        }

        return ans;
    }
};

int main()
{

    return 0;
}