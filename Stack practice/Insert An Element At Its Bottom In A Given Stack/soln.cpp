#include <bits/stdc++.h>
using namespace std;

void insertElement(stack <int> &s, int elem)  //pass by reference
{
    //base case
    if(s.empty())
    {
        s.push(elem);
    }
    else
    {
        int store = s.top();
        s.pop();
        insertElement(s,elem);
        s.push(store);
    }
}

int main()
{
    stack <int> s;
    s.push(7);
    s.push(5);
    s.push(4);
    s.push(1);

    int elem = 9;

    insertElement(s,elem);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}