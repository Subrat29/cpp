#include <bits/stdc++.h>      //Ques: only a stack can be used as an auxilliary space
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    // Step 1: Fetch 1st half and push in new queue
    queue<int> newq;

    int l = q.size() / 2;

    while (q.size() > l)
    {
        int val = q.front();
        newq.push(val);
        q.pop();
    }

    // Step 2: push elem of newq & q in q until newq is not empty
    while (!newq.empty())
    {
        int val = newq.front();
        newq.pop();
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