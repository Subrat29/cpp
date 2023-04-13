#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//tc & sc = O(n^2)

int solve(vector<int> &Satisfaction)
{
    int n = Satisfaction.size();

    // step1 : create dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // step2: analyse base case
    // no need bc dp already initialize by 0;

    // step2 : convert recursive call into dp

    // index = n-1 bc n wala above already handle
    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = index; time >= 0; time--)
        {
            int include = Satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
            int exclude = 0 + dp[index + 1][time];

            dp[index][time] = max(include, exclude);
        }
    }
    return dp[0][0];
}

int maxSatisfaction(vector<int> &satisfaction)
{
    // first sort the array to get maxm ans
    sort(satisfaction.begin(), satisfaction.end());

    return solve(satisfaction);
}

int main()
{

    return 0;
}