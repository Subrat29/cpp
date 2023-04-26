#include <iostream>
using namespace std;

int solve(int n)
{
    if (n <= 1)
        return 1;

    int ans = 0;

    // Assume i as root node
    for (int i = 1; i <= n; i++)
    {
        ans += solve(i - 1) * solve(n - i);
    }
    return ans;
}

int numTrees(int n)
{
    return solve(n);
}

int main()
{

    return 0;
}