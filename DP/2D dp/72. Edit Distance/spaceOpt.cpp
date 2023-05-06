#include <iostream>
#include <vector>
using namespace std;

int solve(string &s1, string &s2)
{
    vector<int> curr(s2.length() + 1, 0);
    vector<int> next(s2.length() + 1, 0);


    // for (int i = 0; i < s1.length(); i++)
    // {
    //     dp[i][s2.length()] = s1.length() - i;
    // }

    for (int j = 0; j < s2.length(); j++)
    {
        next[j] = s2.length() - j; // last wala row
    }

    // step3: convert recursive call into dp
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        for (int j = s2.size() - 1; j >= 0; j--)
        {

            // CATCH HERE -> YE HME BASE CASE SE MILA H, HM BASE CASE SE IDHR LE AAYE ISE
            curr[s2.length()] = s1.length() - i;

            int ans = 0;
            if (s1[i] == s2[j])
            {
                ans = next[j + 1];
            }

            else
            {
                // insert
                int insertAns = 1 + curr[j + 1];

                // replace
                int replaceAns = 1 + next[j + 1];

                // delete
                int deleteAns = 1 + next[j];

                ans = min(insertAns, min(replaceAns, deleteAns));
            }

            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int minDistance(string word1, string word2)
{
    if (word1.length() == 0)
        return word2.length();

    if (word2.length() == 0)
        return word1.length();

    return solve(word1, word2);
}

int main()
{

    return 0;
}