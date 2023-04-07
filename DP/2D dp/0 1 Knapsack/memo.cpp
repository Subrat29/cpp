#include <iostream>
#include <vector>
using namespace std;

//tc : O(n*maxtWeight)
//sc : 

int solve(vector<int> &weight, vector<int> &value, int n, int maxWeight, vector<vector<int>> &dp)
{
    // base case
    if (n == 0)
    {
        if (weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }

    //step3: if dp array contains ans then return 
    if (dp[n][maxWeight] != -1)
        return dp[n][maxWeight];


    int include = 0;
    if (weight[n] <= maxWeight)
        include = value[n] + solve(weight, value, n - 1, maxWeight - weight[n], dp);

    int exclude = 0 + solve(weight, value, n - 1, maxWeight, dp);

    //step2 : store ans in dp
    dp[n][maxWeight] = max(include, exclude);
    return dp[n][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // step1 : create dp array
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));  //rows -> n and column -> weight+1


    return solve(weight, value, n - 1, maxWeight, dp);
}

int main()
{

    return 0;
}