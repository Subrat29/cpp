#include <bits/stdc++.h>
using namespace std;

vector<int> nextgreaterElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() <= curr && s.top() != -1)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4};
    int n = arr.size();

    vector<int> ans = nextgreaterElement(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}