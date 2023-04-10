#include <iostream>
#include <vector>
using namespace std;

//tc: O(n)
//sc: O(n)

int solve(int n, vector<int> &days, vector<int> &cost)
{
    // step1: create dp array
    vector<int> dp(n + 1, INT_MAX);

    // step2: base case
    dp[n] = 0;

    // k shows indexes here ok
    for (int k = n-1; k >= 0; k--)
    {
        // 1 day pass
        int option1 = cost[0] + dp[k + 1];

        int i;

        // 7 day pass
        for (i = k; i < n && days[i] < days[k] + 7; i++);        // these ; is very imp ow shows error
        int option2 = cost[1] + dp[i];

        // 30 day pass
        for (i = k; i < n && days[i] < days[k] + 30; i++);
        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n, days, cost);
}

int main()
{

    return 0;
}