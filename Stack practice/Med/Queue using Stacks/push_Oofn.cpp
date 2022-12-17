#include <bits/stdc++.h>
using namespace std;

class Queue
{
public: 
    stack<int> s1, s2;

    void push(int data)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        if(s1.empty())
        return -1;

        int elem = s1.top();
        s1.pop();
        return elem;
    }

    void print()
    {
        while (!s1.empty())
        {
            cout << s1.top() << " ";
            s1.pop();
        }
    }
};

int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    q.print();

    return 0;
}