#include <iostream>
#include <vector>
using namespace std;

long long solve(int d, int f, int t)
{
    // step1: create dp vector
    vector<long long> curr(t + 1, 0);
    vector<long long> prev(t + 1, 0);

    prev[0] = 1;

    for (int dice = 1; dice <= d; dice++)
    {
        for (int target = 1; target <= t; target++)
        {
            long long ans = 0;
            for (int i = 1; i <= f; i++)
            {
                if (target - i >= 0)
                    ans = ans + prev[target - i];
            }
            curr[target] = ans;
        }
        prev = curr;
    }
    return prev[t];
}

long long noOfWays(int M, int N, int X)
{
    return solve(N, M, X);
}

int main()
{

    return 0;
}