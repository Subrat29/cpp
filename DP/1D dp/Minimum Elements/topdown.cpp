#include <iostream>
#include <vector>
using namespace std;

// tc = O(x.n)  x = amt, n = no of coins available
// sc = O(x)

int solveMemo(vector<int> &num, int x, vector<int> &dp)
{
    // base case
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    // step 3
    if (dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveMemo(num, x - num[i], dp);
        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }

    // step 2
    dp[x] = mini;
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    // step 1
    vector<int> dp(x + 1, -1); // bc of 0 base indexing

    int ans = solveMemo(num, x, dp);
    if (ans == INT_MAX)
        return -1;

    return ans;
}

int main()
{

    return 0;
}