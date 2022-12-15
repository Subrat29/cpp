#include <bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> &q)
{
    stack <int> s;
    
    while (!q.empty())
    {
        int elem = q.front();
        q.pop();
        s.push(elem);
    }

    while (!s.empty())
    {
        int elem = s.top();
        s.pop();
        q.push(elem);
    }  

    return q;
}

void print(queue <int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();                    //dont forget this line bro
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
    
    rev(q);
    print(q);

    return 0;
}