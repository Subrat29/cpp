#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    stack<int> s1, s2;

    void push(int data)
    {
        s1.push(data);
    }

    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int elem = s2.top();
            s2.pop();
            return elem;
        }
        else
        {
            int elem = s2.top();
            s2.pop();
            return elem;
        }
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}