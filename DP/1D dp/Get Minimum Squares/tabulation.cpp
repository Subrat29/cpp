#include <iostream>
#include <vector>
using namespace std;

int solve(int n)
{
    // create dp array
    vector<int> dp(n + 1, INT_MAX);  //not -1

    // base case
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            int temp = j * j;

            if(i-temp >= 0)
            dp[i] = min(dp[i], 1 + dp[i - temp]);
        }
    }
    return dp[n];
}

int MinSquares(int n)
{
    return solve(n);
}

int main()
{

    return 0;
}