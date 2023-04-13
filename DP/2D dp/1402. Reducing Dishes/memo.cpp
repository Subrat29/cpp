#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> &Satisfaction, int index, int time, vector<vector<int>> &dp)
{
    // base case
    if (index == Satisfaction.size())
        return 0;

    // step3: check base case
    if (dp[index][time] != -1)
        return dp[index][time];

    // step2 : store in dp
    int include = Satisfaction[index] * (time + 1) + solve(Satisfaction, index + 1, time + 1, dp);
    int exclude = 0 + solve(Satisfaction, index + 1, time, dp);

    dp[index][time] = max(include, exclude);
    return dp[index][time];
}

int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();

    // step1 : create dp array
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    // first sort the array to get maxm ans
    sort(satisfaction.begin(), satisfaction.end());

    return solve(satisfaction, 0, 0, dp);
}

int main()
{

    return 0;
}