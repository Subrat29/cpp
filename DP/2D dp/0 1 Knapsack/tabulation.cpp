#include <iostream>
#include <vector>
using namespace std;

//tc : O(n*maxweight)
//sc : O(2*maxWeight)

int solve(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // step1 : create dp array
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // step2 : analyse base case
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    //step3: convert recursive call into dp relation
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;

            if (weight[index] <= w)
                include = value[index] + dp[index - 1][w - weight[index]];

            int exclude = 0 + dp[index - 1][w];

            dp[index][w] = max(exclude, include);
        }  
    }
    return dp[n - 1][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n, maxWeight);
}

int main()
{

    return 0;
}