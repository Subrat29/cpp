#include <iostream>
#include <vector>
using namespace std;

// New approch : by use of transaction number

//VERY IMP NOTE: LOOP ME DEKH LO KHI INDEX+1 VAGARAH TO NHI KR RHE HO IF YES THEN +1 IN VECTOR OTHERWISE MAYBE HEAP OVERFLOW MAAR JAYE 

int solve(int k, vector<int> &prices)
{
    int n = prices.size();

    // step1: create dp array
    vector<vector<int>> dp(n + 1, vector<int>(2 * k+1, 0));

    // step2: base case analyz
    // no need

    // step3: convert recursive soln into dp
    for (int index = n - 1; index >= 0; index--)
    {
        for (int transactionNo = 0; transactionNo < 2 * k; transactionNo++)
        {
            int profit = 0;

            // buy allowed
            if (transactionNo % 2 == 0)
            {
                int buyKaro = -prices[index] + dp[index + 1][transactionNo + 1];
                int skipKaro = 0 + dp[index + 1][transactionNo];
                profit = max(buyKaro, skipKaro);
            }
            // buy not allowed
            else
            {
                int sellKaro = prices[index] + dp[index + 1][transactionNo + 1];
                int skipKaro = 0 + dp[index + 1][transactionNo];
                profit = max(sellKaro, skipKaro);
            }
            dp[index][transactionNo] = profit;
        }
    }
    return dp[0][0];
}

int maxProfit(int k, vector<int> &prices)
{
    return solve(k, prices);
}

int main()
{

    return 0;
}