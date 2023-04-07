#include <iostream>
#define MOD 1000000007
using namespace std;

// #define MOD 1000000007;  Here, it not work

//tc : expo

int sum(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

int mul(int a, int b)
{
    return (a % MOD * b % MOD) % MOD;
}

int solve(int n, int k)
{
    if (n == 1)
        return k;

    if (n == 2)
        return sum(k, mul(k, k - 1));

    int ans = sum(mul(solve(n - 2, k), k - 1), mul(solve(n - 1, k), k - 1));
    return ans;
}

int numberOfWays(int n, int k)
{
    return solve(n, k);
}

int main()
{

    return 0;
}