#include <iostream>
#include <vector>
using namespace std;

int solve(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    // step1: create dp array
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0)); //+1 because heap overflow

    // step2: analyze base case
    // no need

    // step3: convert recursive call into dp
    for (int i = l1 - 1; i >= 0; i--)
    {
        for (int j = l2 - 1; j >= 0; j--)
        {
            int ans = 0;
            if (s1[i] == s2[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int longestCommonSubsequence(string text1, string text2)
{
    return solve(text1, text2);
}

int main()
{

    return 0;
}