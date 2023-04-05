#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

// #define MOD 1000000007;  Here, it not work

//tc : O(n), sc : O(n)

int sum(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

int mul(int a, int b)
{
    return (a % MOD * 1LL * b % MOD) % MOD;
    // if we not use then all test case not pass bc of range related problem, solve it by multiply 1ll means 1 in long long format
    // we also multiply 1l also or 1ll
}

int solve(int n, int k)
{
    // step1 : create dp array
    vector<int> dp(n + 1, -1);

    // step2 : base case
    dp[1] = k;
    dp[2] = sum(k, mul(k, k - 1));

    // step3 : convert recursive call into dp relation
    for (int i = 3; i <= n; i++)
    {
        dp[i] = sum(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
    }
    return dp[n];
}

int numberOfWays(int n, int k)
{
    return solve(n, k);
}

int main()
{

    return 0;
}