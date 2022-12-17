#include <bits/stdc++.h>
using namespace std;

class Stack
{
    public:
    queue <int> q;

    void push(int data)
    {
        q.push(data);
        int l = q.size() - 1;

        while (l--)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if(q.empty())
        {
            return -1;
        }

        int elem = q.front();
        q.pop();
        return elem;
    }

    void print()
    {
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.pop();

    s.print();
    return 0;
}