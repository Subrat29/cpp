#include <iostream>
using namespace std;

int solve(string s1, string s2, int i, int j)
{
    // base case
    if (i == s1.length() || j == s2.length())
        return 0;

    int ans = 0;
    if (s1[i] == s2[j])
    {
        ans = 1 + solve(s1, s2, i + 1, j + 1);
    }
    else
    {
        ans = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    }
    return ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    return solve(text1, text2, 0, 0);
}

int main()
{

    return 0;
}