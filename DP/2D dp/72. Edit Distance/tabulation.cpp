#include <iostream>
#include <vector>
using namespace std;

int solve(string &s1, string &s2)
{
    // step1: create a dp array
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), 0));

    // step2: Analyze base case
    for (int i = 0; i < s1.length(); i++)
    {
        dp[i][s2.length()] = s1.length() - i;
    }

    for (int j = 0; j < s2.length(); j++)
    {
        dp[s1.length()][j] = s2.length() - j;
    }

    // step3: convert recursive call into dp
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        for (int j = s2.size() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (s1[i] == s2[j])
            {
                ans = dp[i + 1][j + 1];
            }

            else
            {
                // insert
                int insertAns = 1 + dp[i][j + 1];

                // replace
                int replaceAns = 1 + dp[i + 1][j + 1];

                // delete
                int deleteAns = 1 + dp[i + 1][j];

                ans = min(insertAns, min(replaceAns, deleteAns));
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int minDistance(string word1, string word2)
{
    return solve(word1, word2);
}

int main()
{

    return 0;
}