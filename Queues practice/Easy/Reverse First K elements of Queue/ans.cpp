#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) 
{
    stack <int> s;

    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())                                  //hm for loop use krke print nhi kr skte bc size hr iteration pr badal jata
    {
        q.push(s.top());;
        s.pop();        
    }

    int n = q.size() - k;
    while (n--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    queue <int> ans = modifyQueue(q, k);

    while(!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }

    return 0;
}