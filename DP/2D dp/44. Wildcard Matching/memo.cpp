#include <iostream>
#include <vector>
using namespace std;

bool solve(string &str, int i, string &pattern, int j, vector<vector<int>> &dp)
{
    // base case
    if (i < 0 && j < 0)
        return true;

    if (i >= 0 && j < 0)
        return false;

    if (i < 0 && j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (pattern[k] != '*')
                return false;
        }
        return true;
    }

    // step3: check base case
    if (dp[i][j] != -1)
        return dp[i][j];

    // step2: store in dp
    //  match
    if (str[i] == pattern[j] || pattern[j] == '?')
        return dp[i][j] = solve(str, i - 1, pattern, j - 1, dp);

    else if (pattern[j] == '*')
        return dp[i][j] = (solve(str, i - 1, pattern, j, dp) || solve(str, i, pattern, j - 1, dp));

    else
        return dp[i][j] = false;
    // return false;
}

bool isMatch(string s, string p)
{
    // step1: create a dp vector
    vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));

    return solve(s, s.length() - 1, p, p.length() - 1, dp);
}

int main()
{

    return 0;
}