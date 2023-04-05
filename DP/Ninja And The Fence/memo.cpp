#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

// #define MOD 1000000007;  Here, it not work

//tc : O(n), sc : O(n) + O(n)

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

int solve(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;

    if (n == 2)
        return sum(k, mul(k, k - 1));

    // step3 : base case check
    if (dp[n] != -1)
        return dp[n];

    // step2 : store in dp
    dp[n] = sum(mul(solve(n - 2, k, dp), k - 1), mul(solve(n - 1, k, dp), k - 1));
    return dp[n];
}

int numberOfWays(int n, int k)
{
    // step1 : create dp array
    vector<int> dp(n + 1, -1);

    return solve(n, k, dp);
}

int main()
{

    return 0;
}