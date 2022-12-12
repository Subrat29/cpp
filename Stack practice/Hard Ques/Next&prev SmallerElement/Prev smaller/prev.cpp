#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack <int> s;
    s.push(-1);

    vector <int> ans(n);

    for(int i=0; i<n; i++)
    {
        int curr = arr[i];

        while (s.top() >= curr)
        {
            s.pop();
        }

        // ans.push_back(s.top());   // i did this which is wrong
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector <int> arr = {2,1,4,3};
    int n = arr.size();

    vector <int> ans = prevSmallerElement(arr, n);

    for(int i=0; i<n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}