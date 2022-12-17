#include <bits/stdc++.h>
using namespace std;

class Stack 
{
    public:
    queue<int> q1, q2;

void push(int data)
{

    // step 1: Insert data in q1
    q1.push(data);

    // step 2: push all elem of q2 in q1;
    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }

    // step 3: swap q1 & q2
    queue<int> q = q1;                         //swap(q1, q2)
    q1 = q2;
    q2 = q;
}

void pop()
{
    if(q2.empty())
    return;

    q2.pop();
}

int top()
{
    if(q2.empty())
    return -1;
    
    return q2.front();
}

int size()
{
    return q2.size();
}

};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
 
    cout << "current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
 
    cout << "current size: " << s.size() << endl;
    return 0;

    return 0;
}