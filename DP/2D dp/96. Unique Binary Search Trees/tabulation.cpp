#include <iostream>
#include <vector>
using namespace std;

//Tc : O(n^2)
//Sc : O(n)

// Here, 2 parameters are changing no of nodes & root nodes

int solve(int n)
{
    // step1: create dp vector
    vector<int> dp(n + 1, 0);

    // step2: analyse base cases
    dp[0] = dp[1] = 1;


    // step3: convert recursive soln into dp

    // i = no. of nodes
    for (int i = 2; i <= n; i++)
    {
        // j = root nodes
        for (int j = 1; j <= i; j++)
            dp[i] += dp[j - 1] * dp[i - j];
    }
    return dp[n];
}

int numTrees(int n)
{
    return solve(n);
}

int main()
{

    return 0;
}