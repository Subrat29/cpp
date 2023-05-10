#include <iostream>
using namespace std;

int solve(string &str, int i, string &pattern, int j)
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

    // match
    if (str[i] == pattern[j] || pattern[j] == '?')
        return solve(str, i - 1, pattern, j - 1);

    else if (pattern[j] == '*')
        return (solve(str, i - 1, pattern, j) || solve(str, i, pattern, j - 1));

    else
        return false;
}

bool isMatch(string s, string p)
{
    return solve(s, s.length() - 1, p, p.length() - 1);
}

int main()
{

    return 0;
}