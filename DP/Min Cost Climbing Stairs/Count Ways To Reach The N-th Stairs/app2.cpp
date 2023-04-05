#include <iostream>
using namespace std;

// top to bottom recursive approach

int solve(int n)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    return solve(n - 1) + solve(n - 2);
}

int countDistinctWays(int nStairs)
{
    return solve(nStairs);
}

int main()
{

    return 0;
}