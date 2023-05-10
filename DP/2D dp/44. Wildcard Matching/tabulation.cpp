#include <iostream>
#include <vector>
using namespace std;

//tc &sc = O(m*n)

// Note: less than case ko handle krne ke liye har cheez ko 1 se increment kr do

bool solve(string &str, string &pattern)
{
    // step1: create a dp vector
    vector<vector<int>> dp(str.length() + 1, vector<int>(pattern.length() + 1, 0)); // mark false all

    // step2: analyze base case
    dp[0][0] = true;

    for (int j = 1; j <= pattern.length(); j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (pattern[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    // step3: convert recursive call into dp
    for (int i = 1; i <= str.length(); i++)
    {
        for (int j = 1; j <= pattern.length(); j++)
        {
            //  match
            if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];

            else if (pattern[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

            else
                dp[i][j] = false;
        }
    }
    return dp[str.length()][pattern.length()];
}

bool isMatch(string s, string p)
{
    return solve(s, p);
}

int main()
{

    return 0;
}