#include <iostream>
using namespace std;

int solve(string &s1, string &s2, int i, int j)
{
    //base case
    if (i == s1.length())
        return s2.length() - j;

    if (j == s2.length())
        return s1.length() - i;

    int ans = 0;
    if (s1[i] == s2[j])
        return solve(s1, s2, i + 1, j + 1);

    else
    {
        // insert
        int insertAns = 1 + solve(s1, s2, i, j + 1);

        // replace
        int replaceAns = 1 + solve(s1, s2, i + 1, j + 1);

        // delete
        int deleteAns = 1 + solve(s1, s2, i + 1, j);

        ans = min(insertAns, min(replaceAns, deleteAns));
    }
    return ans;
}

int minDistance(string word1, string word2)
{
    return solve(word1, word2, 0, 0);
}

int main()
{

    return 0;
}