#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;

    int n, s;
    int freespot;

public:
    NStack(int N, int S) // intialize your data structure
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // // initialize top                 Why memset is not working??
        // memset(top, -1, sizeof(top));

        // // initialize next
        // memset(next, 0, sizeof(next));

        // initialize top
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // initialize next
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }

        // update last index value to -1
        next[s - 1] = -1;

        // initialize freespot
        freespot = 0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if (freespot == -1)
            return false;

        // find index
        int index = freespot;

        // insert element into array
        arr[index] = x;

        // update freespot
        freespot = next[index];

        // update next
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check  underflow condition
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main()
{
    // Let us create 3 stacks in an array of size 10
    int s = 3, n = 10;
    NStack Nthstack(s, n);

    // Let us put some items in stack number 2
    Nthstack.push(15, 2);
    Nthstack.push(45, 2);

    // Let us put some items in stack number 1
    Nthstack.push(17, 1);
    Nthstack.push(49, 1);
    Nthstack.push(39, 1);

    // Let us put some items in stack number 0
    Nthstack.push(11, 0);
    Nthstack.push(9, 0);
    Nthstack.push(7, 0);

    cout << "Popped element from stack 2 is " << Nthstack.pop(2) << endl;
    cout << "Popped element from stack 1 is " << Nthstack.pop(1) << endl;
    cout << "Popped element from stack 0 is " << Nthstack.pop(0) << endl;



    return 0;
}