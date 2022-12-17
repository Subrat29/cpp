#include <bits/stdc++.h>
using namespace std;

void solve(stack <int> &s, int count, int size)
{
    //base case
    if(count == size/2)
    {
        s.pop();
        return;
    }

    int store = s.top(); 
    s.pop();

    solve(s, count+1, size);

    s.push(store);
}

void deleteMiddle(stack <int>&s, int size)
{
    int count = 0;
    solve(s,count,size);
}

int main()
{
    stack <int> s;

    // s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    int size = s.size() - 1;   //Use -1 to remove 2, else it remove 3

    deleteMiddle(s, size);    //fn ka name delete nhi de skte vo predefined h.

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}