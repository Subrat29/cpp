#include <iostream>
#include <vector>
using namespace std;

// tc : O(1)   bc days are 1 to 365 which is constant

int solve(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    // base case
    if (index >= n)
        return 0;

    //step3 : check 
    if(dp[n] != -1)
    return dp[n];

    // 1 day pass
    int option1 = cost[0] + solve(n, days, cost, index + 1, dp);

    // 7 day pass
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++);             // these ; is very imp ow shows error
    int option2 = cost[1] + solve(n, days, cost, i, dp);

    // 30 day pass
    for (i = index; i < n && days[i] < days[index] + 30; i++);
    int option3 = cost[2] + solve(n, days, cost, i, dp);

    //step2 : store in dp
    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    //step1: create dp array
    vector<int> dp(n+1, -1);

    return solve(n, days, cost, 0, dp);
}

int main()
{

    return 0;
}