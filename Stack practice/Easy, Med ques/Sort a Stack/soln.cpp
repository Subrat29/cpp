#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack <int> &s, int elem)
{
    //base case
    if(s.empty() || s.top() < elem )
    {
        s.push(elem);
        return;
    }

        int temp = s.top();
        s.pop();

        //recursive call
        insertSorted(s, elem);

        s.push(temp);
}

void sortStack(stack <int> &s)
{
    //base case
    if(s.empty())
    {
        return;
    }

    int store = s.top();
    s.pop();

    //recursive call
    sortStack(s);

    insertSorted(s, store);
}

int main()
{
    stack <int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    

    return 0;
}