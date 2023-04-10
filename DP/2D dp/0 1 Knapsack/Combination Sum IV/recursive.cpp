#include <iostream>
#include <vector>
using namespace std;

//tc: expo

// Out of 2 parameter only 1 is changing => 1d DP

int solve(vector<int> &num, int tar)
{
    // base case
    if (tar < 0)
        return 0;

    if (tar == 0)
        return 1;

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solve(num, tar - num[i]);
    }

    return ans;
}

int findWays(vector<int> &num, int tar)
{
    return solve(num, tar);
}

int main()
{

    return 0;
}