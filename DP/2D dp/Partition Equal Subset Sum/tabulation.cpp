#include <iostream>
#include <vector>
using namespace std;

//tc = total*N

bool solve(int arr[], int N, int total)
{
    // step1: create dp vector
    vector<vector<int>> dp(N + 1, vector<int>(total + 1, 0));

    // step2: analysis of base case
    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;

    // Note: step1, 2 me N+1, i<=N bc to remove error due to dp[index + 1]

    // step3: convert recursive relation in dp
    for (int index = N - 1; index >= 0; index--)
    {
        for (int target = 0; target <= total / 2; target++)
        {
            bool incl = 0;
            if (target - arr[index] >= 0)
                incl = dp[index + 1][target - arr[index]];
            bool excl = dp[index + 1][target];

            dp[index][target] = incl || excl;
        }
    }
    return dp[0][total / 2];
}

int equalPartition(int N, int arr[])
{
    int total = 0;
    for (int i = 0; i < N; i++)
        total += arr[i];

    // if odd
    if (total & 1)
        return 0;

    return solve(arr, N, total);
}

int main()
{

    return 0;
}