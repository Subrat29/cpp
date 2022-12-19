#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int> s;

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.size() != 0 && arr[s.top()] <= curr)
        {
            s.pop();
        }

        if (s.size() == 0 || arr[s.top()] <= curr)
        {
            ans[i] = 0;
            s.push(i);
        }
        else
        {
            ans[i] = s.top() - i;
            s.push(i);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = arr.size();

    vector<int> ans = nextSmallerElement(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}