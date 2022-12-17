#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int elem)
{
    // base case
    if (s.empty())
    {
        s.push(elem);
        return; // forget this
    }

    int temp = s.top();
    s.pop();

    // recursive call
    insertAtBottom(s, elem);

    s.push(temp);
}

void reverseStack(stack<int> &s) // see notes for diagram represent
{
    // base case
    if (s.empty())
    {
        return;
    }

    int store = s.top();
    s.pop();

    // recursive call
    reverseStack(s);

    insertAtBottom(s, store);
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(6);
    s.push(8);
    s.push(1);

    // while (!s.empty())             //we cant use two while together bc they pop all elem when print
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    // cout << endl;

    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}