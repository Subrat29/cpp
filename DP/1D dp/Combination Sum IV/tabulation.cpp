#include <iostream>
#include <vector>
using namespace std;

//tc: O(tar*num)

int solve(vector<int> &num, int tar)
{
    // step1: Create dp array
    vector<int> dp(tar + 1, 0);

    // step2: Base case
    dp[0] = 1;

    // step3: convert recc relation into dp relation

    // traversing from target 1 to tar
    for (int i = 1; i <= tar; i++)
    {
        // traversing on num vector
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
                dp[i] += dp[i - num[j]];
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    return solve(num, tar);
}

int main()
{

    return 0;
}