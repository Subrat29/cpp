#include <bits/stdc++.h>
using namespace std;

int main()
{
    //creation of queues
    queue <int> q;

    q.push(1);
    cout << "Front of q is : " << q.front() << endl;

    q.push(2);
    cout << "Front of q is : " << q.front() << endl;

    q.push(3);
    cout << "Front of q is : " << q.front() << endl;

    cout << "size: " << q.size() << endl;

    q.pop();

    cout << "size: " << q.size() << endl;

    if(q.empty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }
    
    return 0;
}