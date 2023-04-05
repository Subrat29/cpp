#include <iostream>
#include <vector>
using namespace std;

// tc = O(x.n)  x = amt, n = no of coins available
// sc = O(x)

// dp[i] = min no of coins required to make target i

int solveTab(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        // i m trying to solve for every amount from 1 to x
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
        }
    }

    if (dp[x] == INT_MAX)
        return -1;

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    return solveTab(num, x);
}

int main()
{

    return 0;
}