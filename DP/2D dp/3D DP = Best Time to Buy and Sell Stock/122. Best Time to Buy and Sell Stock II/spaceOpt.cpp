#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &prices)
{
    int n = prices.size();

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    // curr = dp[index]
    // next = dp[index + 1]

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            // buy allowed
            if (buy)
            {
                int buyKaro = -prices[index] + next[0];
                int skipKaro = 0 + next[1];
                profit = max(buyKaro, skipKaro);
            }
            // buy not allowed
            else
            {
                int sellKaro = prices[index] + next[1];
                int skipKaro = 0 + next[0];
                profit = max(sellKaro, skipKaro);
            }
            // step2: store in dp array
            curr[buy] = profit;
        }
        next = curr;  //always forget*
    }
    return next[1];
}

int maxProfit(vector<int> &prices)
{
    return solve(prices);
}

int main()
{

    return 0;
}