#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

// #define MOD 1000000007;  Here, it not work

// tc : O(n), sc : O(n)

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
    int prev2 = k;
    int prev1 = sum(k, mul(k, k - 1));

    // step3 : convert recursive call into dp relation
    for (int i = 3; i <= n; i++)
    {
        int ans = sum(mul(prev2, k - 1), mul(prev1, k - 1));

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int numberOfWays(int n, int k)
{
    return solve(n, k);
}

int main()
{

    return 0;
}