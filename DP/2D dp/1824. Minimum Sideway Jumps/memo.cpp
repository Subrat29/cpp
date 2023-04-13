#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &obstacles, int currlane, int currpos, vector<vector<int>> &dp)
{
    int n = obstacles.size() - 1;

    // base case
    if (currpos == n)
        return 0;

    // step2: check base case
    if (dp[currlane][currpos] != -1)
        return dp[currlane][currpos];

    // if no obstacle on current lane
    if (obstacles[currpos + 1] != currlane)
    {
        return solve(obstacles, currlane, currpos + 1, dp);
    }
    // if obstacle present on current lane
    else
    {
        // sideways jump
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currlane != i && obstacles[currpos] != i)
                ans = min(ans, 1 + solve(obstacles, i, currpos, dp));
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
}

int minSideJumps(vector<int> &obstacles)
{
    int n = obstacles.size();

    // step1: create dp array  
    
    //row = 4, col = n
    vector<vector<int>> dp(4, vector<int>(n, -1));

    return solve(obstacles, 2, 0, dp);
}

int main()
{

    return 0;
}