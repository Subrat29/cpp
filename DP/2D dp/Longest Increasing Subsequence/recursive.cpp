#include <iostream>
using namespace std;

int solve(int n, int a[], int curr, int prev)
{
    // base case
    if (curr == n)
        return 0;

    // include
    int take = 0;
    if (prev == -1 || a[curr] > a[prev])
        take = 1 + solve(n, a, curr + 1, curr);

    // exclude
    int notTake = 0 + solve(n, a, curr + 1, prev);

    return max(take, notTake);
}

int longestSubsequence(int n, int a[])
{
    return solve(n, a, 0, -1);
}

int main()
{

    return 0;
}