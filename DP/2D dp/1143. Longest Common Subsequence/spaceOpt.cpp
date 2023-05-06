#include <iostream>
#include <vector>
using namespace std;

int solve(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();

    int l3 = max(l1, l2);

    vector<int> curr(l3, 0);  //we use l2 also but not l1 pta nii ques me dalkr shi aa ra h
    vector<int> next(l3, 0);

    for (int i = l1 - 1; i >= 0; i--)
    {
        for (int j = l2 - 1; j >= 0; j--)
        {
            int ans = 0;
            if (s1[i] == s2[j])
            {
                ans = 1 + next[j + 1];
            }
            else
            {
                ans = max(next[j], curr[j + 1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int longestCommonSubsequence(string text1, string text2)
{
    return solve(text1, text2);
}

int main()
{

    return 0;
}