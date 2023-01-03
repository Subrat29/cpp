#include <bits/stdc++.h>
using namespace std; 

vector<int> nextGreaterElements(vector<int> v)
{
    stack<int> s;
    s.push(-1);

    int l = v.size();
    vector<int> ans(l);                // Mistake vector size not define

    for (int i = l - 1; i >= 0; i--)
    {
        while (s.top() <= v[i] && s.top() != -1)
        {
            s.pop();
        }
        s.push(v[i]);
    }

    for (int i = l - 1; i >= 0; i--)
    {
        while (s.top() <= v[i] && s.top() != -1)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(v[i]);
    }

    return ans;
}

int main()
{
    vector<int> v = {100,1,11,1,120,111,123,1,-1,-100}; 
    //Op = {120 11 120 120 123 123 -1 -1 100 100} ,exp Op = {120 11 120 120 123 123 -1 100 100 100}

    vector<int> ans = nextGreaterElements(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}