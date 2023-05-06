#include <iostream>
#include <vector>
using namespace std;

int solve(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i == s1.length() || j == s2.length())
        return 0;

    // step3: check base case
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (s1[i] == s2[j])
    {
        ans = 1 + solve(s1, s2, i + 1, j + 1, dp);
    }
    else
    {
        ans = max(solve(s1, s2, i + 1, j, dp), solve(s1, s2, i, j + 1, dp));
    }
    // step2: store in dp array
    return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    int l1 = text1.length();
    int l2 = text2.length();

    // step1: create dp array
    vector<vector<int>> dp(l1, vector<int>(l2, -1));

    return solve(text1, text2, 0, 0, dp);
}

int main()
{

    return 0;
}