#include <bits/stdc++.h>
using namespace std;

class kQueue                     //DRY RUN FOR SAMAJNE KE LIYE BRO, phat gyi isme to:)
{
public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;

    //constructor
    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        front = new int[k];        //k size array 
        rear = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;
        
        arr = new int[n];
        freeSpot = 0; 
    }

    void enqueue(int data, int qn)
    {
        //Overflow
        if(freeSpot == -1)
        {
            cout << "No empty space is presented" << endl;
            return; 
        }

        //find first free index
        int index = freeSpot;

        //update freespot
        freeSpot = next[index];

        //check whether first elem 
        if(front[qn-1] == -1)
        {
            front[qn-1] = index;
        }
        else
        {
            next[rear[qn-1]] = index;
        }

        //update next
        next[index] = -1;

        //update rear
        rear[qn-1] = index;         //qn-1 bc 0 base indexing

        //push elem
        arr[index] = data;
    }

    int dequeue(int  qn)
    {
        //underflow 
        if(front[qn-1] == -1)
        {
            cout << "Queue is empty" << endl;
            return INT_MAX;
        }

        //find index to pop
        int index = front[qn-1];

        //front ko aage badhao
        front[qn-1] = next[index];

        //manage freeslot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main()  
{

    // Let us create 3 queue in an array of size 10
    int k = 3, n = 10;
    kQueue ks(n, k);                                    //n,k pass krna hi padega bc constructor me pass h
 
    // Let us put some items in queue number 2
    ks.enqueue(15, 2);
    ks.enqueue(45, 2);
 
    // Let us put some items in queue number 1
    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);
 
    // Let us put some items in queue number 0
    ks.enqueue(11, 3);
    ks.enqueue(9, 3);
    ks.enqueue(7, 3);
 
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 3 is " << ks.dequeue(3) << endl;

    return 0;
}