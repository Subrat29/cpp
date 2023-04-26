#include <iostream>
#include <vector>
using namespace std;

bool solve(int index, int arr[], int N, int target, vector<vector<int>>&dp)
{
    // base case
    if (index >= N)
        return 0;
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;

    // step3: check base case
    if (dp[index][target] != -1)
        return dp[index][target];

    bool incl = solve(index + 1, arr, N, target - arr[index], dp); // index++ gives error so dont use it
    bool excl = solve(index + 1, arr, N, target, dp);

    // step2: store in dp
    return dp[index][target] = incl || excl;
}

int equalPartition(int N, int arr[])
{
    int total = 0;
    for (int i = 0; i < N; i++)
        total += arr[i];

    // if odd
    if (total & 1)
        return 0;

    // if even
    int target = total / 2;

    // step1: create dp vector
    vector<vector<int>> dp(N, vector<int>(target + 1, -1));
    return solve(0, arr, N, target, dp);
}

int main()
{

    return 0;
}