#include<iostream>
using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
      
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x)
    {
        //check full or not
        if(isFull())
        {
            return false;
        }

        else if(isEmpty())  //1st elem insert
        {
            front = rear = 0;
        }

        else if(front == 0 && rear != size-1)  //cyclic nature maintain
        {
            front = size-1;
        }

        else
        {
            front--;         //normal flow
        }

        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        //check full or not
        if(isFull())
        {
            return false;
        }

        else if(isEmpty())  //1st elem insert
        {
            front = rear = 0;
        }

        else if(rear == size-1 && front != 0)  //cyclic nature maintain
        {
            rear = 0;
        }

        else
        {
            rear++;         //normal flow
        }

        arr[rear] = x;
        return true;       
    }

    int popFront()
    {
         if(isEmpty())       //to check queue is empty or not
        {
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

    int popRear()
    {
         if(isEmpty())       //to check queue is empty or not
        {
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear)     //if single elem is present
        {
            front = rear = -1;
        }

        else if(rear == 0)
        {
            rear = size-1 ;        //to maintain cyclic nature
        }
        else
        {
            rear--;          //normal flow
        }

        return ans;
    }

    int getFront() //return the first element of the deque
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int getRear()
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    bool isEmpty()
    {
        if(front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if( (front == 0 && rear == size-1) || (front !=0 && rear == (front-1)%(size-1)) )  //like: rear=front+1
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