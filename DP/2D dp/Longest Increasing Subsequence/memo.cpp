#include <iostream>
#include <vector>
using namespace std;

// tc &  sc = O(n^2)

int solve(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
{
    // base case
    if (curr == n)
        return 0;

    // step3: check base case
    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // include
    int take = 0;
    if (prev == -1 || a[curr] > a[prev])
        take = 1 + solve(n, a, curr + 1, curr, dp);

    // exclude
    int notTake = 0 + solve(n, a, curr + 1, prev, dp);

    // step2 : store in dp
    return dp[curr][prev + 1] = max(take, notTake); //+1 Use bc -1 ki vajay se invalid na aaye thats why use +1 coordinate change
}

int longestSubsequence(int n, int a[])
{
    // row : 0 -> n-1 then total n element
    // col : -1 -> n-1 then total n+1 element

    // step1 : create dp vector
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(n, a, 0, -1, dp);
}

int main()
{

    return 0;
}