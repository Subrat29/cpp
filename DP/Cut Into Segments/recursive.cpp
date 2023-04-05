#include <iostream>
#include <limits.h>
using namespace std;

int solve(int n, int x, int y, int z)
{
    //base case
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    int a = solve(n - x, x, y, z) + 1; // add 1 bc to calculate n wala soln also
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;

    int ans = max(a, max(b, c));
    return ans;
}

int cutSegments(int n, int x, int y, int z)
{
    int ans = solve(n, x, y, z);

    if (ans < 0)
        return 0;

    return ans;
}

int main()
{

    return 0;
}