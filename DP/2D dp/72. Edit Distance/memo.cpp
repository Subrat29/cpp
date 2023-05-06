#include <iostream>
#include <vector>
using namespace std;

int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i == s1.length())
        return s2.length() - j;

    if (j == s2.length())
        return s1.length() - i;

    // step3: check base case
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (s1[i] == s2[j])
        return solve(s1, s2, i + 1, j + 1, dp);

    else
    {
        // insert
        int insertAns = 1 + solve(s1, s2, i, j + 1, dp);

        // replace
        int replaceAns = 1 + solve(s1, s2, i + 1, j + 1, dp);

        // delete
        int deleteAns = 1 + solve(s1, s2, i + 1, j, dp);

        ans = min(insertAns, min(replaceAns, deleteAns));
    }
    // step2: store in dp
    return dp[i][j] = ans;
}

int minDistance(string word1, string word2)
{
    // int n = max(word2.length(), word1.length());

    // step1: create a dp array
    vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));

    return solve(word1, word2, 0, 0, dp);
}

int main()
{

    return 0;
}