#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(int price[], int n)
{
    stack<int> s;
    s.push(0);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        while (s.top() != 0 && price[s.top()] <= price[i])
        {
            s.pop();
        }

        ans[i] = i - s.top() + 1;
        s.push(i+1);
    }
    return ans;
}

int main()
{
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(int);

    vector<int> ans = calculateSpan(price, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}