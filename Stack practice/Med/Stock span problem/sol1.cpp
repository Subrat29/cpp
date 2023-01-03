#include <bits/stdc++.h> //Mainly, peeche kitne days the jiske stock price aaj jo h usse kam the, or prev greater elem
using namespace std;

vector<int> calculateSpan(int price[], int n)
{
    stack<int> s;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && price[s.top()] <= price[i])
        {
            s.pop();
        }

        if (s.empty())                // if koi bhi elem greater nhi mila, stack empty hone tk bhi then do this
        {
            ans[i] = i + 1;           // ans[i] = 1; me ye kr rha h 
        }
        else                          // if greater elem mil gya then do this
        {
            ans[i] = i - s.top();
        }

        s.push(i);
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