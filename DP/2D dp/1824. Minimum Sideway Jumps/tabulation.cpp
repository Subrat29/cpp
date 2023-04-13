#include <iostream>
#include <vector>
using namespace std;

//tc: O(4*n)
//sc: O(4*n) ~ O(n)

int solve(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;

    // step1: create dp array
    vector<vector<int>> dp(4, vector<int>(n+1, 1e9));

    // base case
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for (int currpos = n - 1; currpos >= 0; currpos--) // currpos
    {
        for (int currlane = 1; currlane <= 3; currlane++) // currlane
        {
            // if no obstacle on current lane
            if (obstacles[currpos + 1] != currlane)
            {
                dp[currlane][currpos] = dp[currlane][currpos + 1];
            }
            // if obstacle present on current lane
            else
            {
                // sideways jump
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if (currlane != i && obstacles[currpos] != i)
                        ans = min(ans, 1 + dp[i][currpos+1]);      // Imp Tricky here: currpos+1 not currpos see video
                }
                dp[currlane][currpos] = ans;
            }
        }
    }
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}

int minSideJumps(vector<int> &obstacles)
{
    return solve(obstacles);
}

int main()
{

    return 0;
}