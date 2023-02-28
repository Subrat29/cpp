#include<iostream>
using namespace std;

class Stack
{
public:
    // properties
    int *arr;
    int top;
    int size;

    // behavior

    // constructor
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];          // arr = new int(size); it is wrong gives error
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1) // >1 not >0
        {
            top++;               //sequence matter, baad me top++ then condn is >=1 (dry run)
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }

        else
        {
            cout << "Stack Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
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

    Stack st(5);  // here 5 is size of stack

    st.push(1);
    st.push(2);
    st.push(3);    
    st.push(4);
    st.push(5);

    //now push when size is full
    st.push(6);
    st.push(7);

    //print top element
    cout << st.peek() << endl;

    //pop top element & then print top element
    st.pop();
    cout << st.peek() << endl;

    //check stack is empty or not
    if(st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Not Empty" << endl;
    }

    //print stack
    while (!st.isEmpty())
    {
        int p = st.peek();
        st.pop();
        cout << p << " ";
    }
    
    return 0;
}