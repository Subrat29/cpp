#include <iostream>
#include <vector>
using namespace std;

// n-1 se start kiya h process
//tc : O(n*maxWeight)

int solve(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // base case
    // if only 1 item to steal, then just compare its weight with the knapsack capacity
    if (n == 0)
    {
        if (weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }

    int include = 0;
    if(weight[n] <= maxWeight)
    include = value[n] + solve(weight, value, n - 1, maxWeight - weight[n]);

    int exclude = 0 + solve(weight, value, n - 1, maxWeight);

    int ans = max(include, exclude);
    return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n-1, maxWeight);
}

int main()
{

    return 0;
}