#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    // Step 1: Fetch 1st half and push in stack
    stack<int> s;

    int l = q.size() / 2;

    while (q.size() > l)
    {
        int val = q.front();
        s.push(val);
        q.pop();
    }

    // Step 2: push elem of stack in queue
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // Step 3: Pop 1st half of q and push at last
    while (l--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    // Step 4: Again fetch 1st half and push in stack
    while (q.size() > l)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // Step 5: Again push elem of stack in queue
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    interLeaveQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}